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
const int MAXN = 200050;
int n,q,a[MAXN];
int cnt,head[MAXN],nxt[MAXN<<1],to[MAXN<<1],val[MAXN<<1],val2[MAXN<<1];
void add(int u,int v,int w,int w2){
    nxt[++cnt]=head[u],head[u]=cnt,to[cnt]=v;
    val[cnt]=w,val2[cnt]=w2;
}
int fa[MAXN][21],dep[MAXN];
int f[MAXN],g[MAXN],up[MAXN][21],down[MAXN][21];
void dp(int p,int fat){
    f[p]=a[p];
    for(int i=head[p],t;i;i=nxt[i])if((t=to[i])!=fat){
        dp(t,p);
        f[p]+=max(0,f[t]-val[i]-val2[i]);
    }
}
void dp2(int p,int fat){
    for(int i=head[p],t;i;i=nxt[i])if((t=to[i])!=fat){
        up[t][0]=f[p]+f[t]-val2[i]-max(0,f[t]-val[i]-val2[i]);
        down[t][0]=f[p]+f[t]-val[i]-max(0,f[t]-val[i]-val2[i]);
        g[t]=max(0,g[p]+up[t][0]-f[t]-val2[i]);
        dp2(t,p);
    }
}

void dfs(int p,int fat){
    fa[p][0]=fat,dep[p]=dep[fat]+1;
    fu(i,1,20,1,1){
        fa[p][i]=fa[fa[p][i-1]][i-1];
        up[p][i]=up[p][i-1]+up[fa[p][i-1]][i-1]-f[fa[p][i-1]];
        down[p][i]=down[p][i-1]+down[fa[p][i-1]][i-1]-f[fa[p][i-1]];
    }
    for(int i=head[p],t;i;i=nxt[i])if((t=to[i])!=fat){
        dfs(t,p);
    }
}
int lca(int u,int v){
    if(dep[u]<dep[v])swap(u,v);
    fd(i,20,1,1,1)if(dep[fa[u][i]]>=dep[v])u=fa[u][i];
    if(u==v)return u;
    fd(i,20,1,1,1)if(fa[u][i]!=fa[v][i])u=fa[u][i],v=fa[v][i];
    return fa[u][0];
}
int jump(int u,int lc,int tp){
    int res=0;
    fd(i,20,1,1,1){
        if(dep[fa[u][i]]>=dep[lc]){
            res=res+(!tp)?up[u][i]:down[u][i];
            u=fa[u][i];
        }
    }
    return res;
}
int query(int u,int v){
    int lc=lca(u,v);
    return jump(u,lc,0)+jump(v,lc,0)+g[lc]-f[lc];
}
signed main(){
    n=read(),q=read();
    fu(i,1,n,1,1)a[i]=read();
    fu(i,1,n-1,1,1){
        int x=read(),y=read(),z1=read(),z2=read();
        add(x,y,z1,z2),add(y,x,z2,z1);
    }
    dp(1,0),dp2(1,0),dfs(1,0);
    while(q--){
        int u=read(),v=read();
        printf("%d\n",query(u,v));
    }
}