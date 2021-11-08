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
typedef long long ll;
const int MAXN = 100050, MAXK = 20;
int n,q;
int cnt,head[MAXN],to[MAXN<<1],nxt[MAXN<<1],val[MAXN<<1];
void add(int u,int v,int w){nxt[++cnt]=head[u],head[u]=cnt,to[cnt]=v,val[cnt]=w;}
int dep[MAXN],fa[MAXN][21];
ll dis[MAXN];
void dfs(int p,int fat){
    fa[p][0]=fat,dep[p]=dep[fat]+1;
    fu(i,1,MAXK,1,1){
        fa[p][i]=fa[fa[p][i-1]][i-1];
    }
    for(int i=head[p],t;i;i=nxt[i])if((t=to[i])!=fat){
        dis[t]=dis[p]+val[i];
        dfs(t,p);
    }
}
signed main(){
    n=read(),q=read();
    fu(i,1,n-1,1,1){
        int u=read(),v=read(),w=read();
        add(u,v,w),add(v,u,w);
    }

}