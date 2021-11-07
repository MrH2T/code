#include<bits/stdc++.h>
#define rint register int
#define fu(i,a,b,d,c) for(rint i=a;i<=b&&c;i+=d)
#define fd(i,a,b,d,c) for(rint i=a;i>=b&&c;i-=d)
using namespace std;
inline int read(){
	char c=0,f=1;int num=0;
	while(c<'0'||c>'9'&&c!='-')((c=getchar())=='-')&&(f=-f);
	while(c>='0'&&c<='9')num=(num<<1)+(num<<3)+(c^48),c=getchar();
	return num*f;
}
const int MAXN = 1e6+50;
int n,m;
int cnt,head[MAXN],to[MAXN<<1],nxt[MAXN<<1],val[MAXN<<1];
void add(int u,int v,int w){
	nxt[++cnt]=head[u],head[u]=cnt,to[cnt]=v,val[cnt]=w;
}
int dfn[MAXN],low[MAXN],dcnt;
int stk[MAXN],estk[MAXN],etop,top,vcnt;
vector<int> vdc[MAXN];
void tarjan(int p){
    dfn[p]=low[p]=++dcnt;
    stk[++top]=p;
    if(p==1&&head[p]==0){
        vdc[++vcnt].push_back(p);
        return;
    }
    for(int i=head[p];i;i=nxt[i]){
        int t=to[i];
        if(!dfn[t]){
            tarjan(t),low[p]=min(low[p],low[t]);
            if(dfn[p]<=low[t]){
                vcnt++;
                int tmp=0;
                do{
                    tmp=stk[top--];
                    vdc[vcnt].push_back(tmp);
                }while(tmp!=t);
                vdc[vcnt].push_back(p);
            }
        }
        else low[p]=min(low[p],dfn[t]);
    }
}
bool bke[MAXN],bk[MAXN];
vector<int> egs[MAXN];
signed main(){
	n=read(),m=read();
	fu(i,1,m,1,1){
		int u=read(),v=read();
		add(u,v,i),add(v,u,i);
	}
    tarjan(1);
    fu(i,1,vcnt,1,1){
        for(auto j:vdc[i])bk[j]=1;
        for(auto j:vdc[i]){
            for(int k=head[j];k;k=nxt[k]){
                int t=to[k];
                if(bk[t]&&!bke[val[k]]){
                    bke[val[k]]=1;
                    egs[i].push_back(val[k]);
                }
            }
        }
        for(auto j:vdc[i])bk[j]=0;
    }
    int ans=0;
    fu(i,1,vcnt,1,1){
        if(vdc[i].size()==egs[i].size()){
            for(auto j:egs[i])ans^=j;
        }
    }
    printf("%d",ans);
}