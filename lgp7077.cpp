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
const int MAXN = 100050, MOD = 998244353;
int tp[MAXN],pos[MAXN],val[MAXN];
vector<int> to[MAXN],frm[MAXN];
int n,m,a[MAXN],cnt[MAXN],tim[MAXN];
int deg[MAXN];
queue<int>qu;
void getTim(){
    memset(deg,0,sizeof(deg));
    while(!qu.empty())qu.pop();
    fu(i,0,m,1,1)if((deg[i]=to[i].size())==0)qu.push(i);
    while(!qu.empty()){
        int fr=qu.front();qu.pop();
        for(int v:frm[fr]){
            tim[v]=1LL*tim[v]*tim[fr]%MOD;
            if(!--deg[v])qu.push(v);
        }
    }
}
void getCnt(){
    memset(deg,0,sizeof(deg));
    while(!qu.empty())qu.pop();
    fu(i,0,m,1,1)if((deg[i]=frm[i].size())==0)qu.push(i);
    while(!qu.empty()){
        int fr=qu.front();qu.pop();
        int tmp=1;
        for(int i=to[fr].size()-1;i>=0;i--){
            int v=to[fr][i];
            cnt[v]=(1LL*cnt[v]+1LL*cnt[fr]*tmp%MOD)%MOD;
            tmp=1LL*tmp*tim[v]%MOD;
            if(!--deg[v])qu.push(v);
        }
    }
}
signed main(){
    n=read();
    fu(i,1,n,1,1)a[i]=read();
    m=read();
    fu(i,1,m,1,1){
        tp[i]=read();
        if(tp[i]==1)pos[i]=read(),val[i]=read(),tim[i]=1;
        else if(tp[i]==2)tim[i]=read();
        else {
            tim[i]=1;
            int k=read();
            fu(j,1,k,1,1){
                int v=read();
                to[i].push_back(v),frm[v].push_back(i);
            }
        }
    }
    tim[0]=cnt[0]=1;
    int q=read();
    fu(i,1,q,1,1){int v=read();to[0].push_back(v),frm[v].push_back(0);}
    getTim(),getCnt();
    fu(i,1,n,1,1)a[i]=1LL*a[i]*tim[0]%MOD;
    fu(i,1,m,1,1){
        if(tp[i]==1){
            a[pos[i]]=(1LL*a[pos[i]]+1LL*cnt[i]*val[i])%MOD;
        }
    }
    fu(i,1,n,1,1)printf("%d ",a[i]);
}