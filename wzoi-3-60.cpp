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
const int MAXN=100050,MAXM = 200050;
struct edge{
    int u,v;
}e[MAXM<<1];
int n,m,cnt=0,deg[MAXN];
int ccnt=0,head[MAXN],nxt[MAXM],to[MAXM];
void add(int u,int v){
    nxt[++ccnt]=head[u],head[u]=ccnt,to[ccnt]=v;
}
int vis[MAXN];
signed main(){
    n=read(),m=read();
    fu(i,1,m,1,1){
        int u=read(),v=read();
        e[++cnt]={u,v};
        deg[u]++,deg[v]++;
    }
    fu(i,1,cnt,1,1){
        if(deg[e[i].u]<deg[e[i].v]||deg[e[i].u]==deg[e[i].v]&&e[i].u<e[i].v)add(e[i].u,e[i].v);
        else add(e[i].v,e[i].u);
    }
    int ans=0;
    fu(i,1,n,1,1){
        for(int j=head[i];j;j=nxt[j])vis[to[j]]=i;
        for(int j=head[i];j;j=nxt[j]){
            for(int k=head[to[j]];k;k=nxt[k]){
                if(vis[to[k]]==i)ans++;
            }
        }
    }
    printf("%d",ans);
}