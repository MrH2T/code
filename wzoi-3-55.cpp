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
const int MAXN = 600050;
int cnt,head[MAXN],to[MAXN<<1],nxt[MAXN<<1],val[MAXN<<1];
void add(int u,int v,int w){nxt[++cnt]=head[u],head[u]=cnt,to[cnt]=v,val[cnt]=w;}
int n,m;
int sz[MAXN],fa[MAXN],f[MAXN][21],mx[MAXN][21],dep[MAXN];
int cntt;
int _find(int u){
    return u==fa[u]?u:fa[u]=_find(fa[u]);
}
void dfs(int p,int fat){
    dep[p]=dep[fat]+1;
    f[p][0]=fat;
    fu(i,1,20,1,1)f[p][i]=f[f[p][i-1]][i-1],mx[p][i]=max(mx[p][i-1],mx[f[p][i-1]][i-1]);
    for(int i=head[p];i;i=nxt[i])if(to[i]!=fat){
        mx[to[i]][0]=val[i];
        dfs(to[i],p);
    }
}
void merge(int u,int v){
    int f_u=_find(u),f_v=_find(v);cntt++;
    if(f_u==f_v)return;
    if(sz[f_u]<sz[f_v])swap(u,v),swap(f_u,f_v);
    sz[f_u]+=sz[f_v],fa[f_v]=f_u;
    sz[f_v]=0;
    add(u,v,cntt),add(v,u,cntt);
    mx[v][0]=cntt;
    dfs(v,u);
}
int query(int u,int v){
    if(_find(u)!=_find(v))return 0;
    if(dep[u]<dep[v])swap(u,v);
    int mxx=0;
    fd(i,20,0,1,1){
        if(dep[f[u][i]]>=dep[v]){
            mxx=max(mxx,mx[u][i]);
            u=f[u][i];
        }
    }
    if(u==v)return mxx;
    fd(i,20,0,1,1){
        if(f[u][i]!=f[v][i]){
            mxx=max(mxx,max(mx[u][i],mx[v][i]));
            u=f[u][i],v=f[v][i];
        }
    }
    return max(mxx,max(mx[u][0],mx[v][0]));
}
signed main(){
    n=read(),m=read();int last=0;
    fu(i,1,n,1,1)fa[i]=i,sz[i]=1;
    fu(i,1,m,1,1){
		int op=read(),u=read()^last,v=read()^last;
        if(op==0){
            merge(u,v);
        }else{
            printf("%d\n",last=query(u,v));
        }
    }
}
