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
const int MAXN = 100050;
int n,m,a[MAXN],capt;
int _min(int a,int b){return a<b?a:b;}
int _swap(int&a,int&b,int t=0){return (t=a,a=b,b=t)&0;}
namespace CFStar{
    int cf_cnt,head[MAXN],nxt[MAXN<<1],to[MAXN<<1];
    void add(int u,int v){nxt[++cf_cnt]=head[u],head[u]=cf_cnt,to[cf_cnt]=v;}
}
using namespace CFStar;
namespace SLPF{
    int id_cnt,id[MAXN],val[MAXN],fa[MAXN],dep[MAXN],sz[MAXN];
    int top[MAXN],son[MAXN];
    namespace SegmentTree{
        struct node{int l,r,mn,tag;}tr[MAXN<<2];
        #define l(p) tr[p].l
        #define r(p) tr[p].r
        #define mn(p) tr[p].mn
        #define tag(p) tr[p].tag
        #define ls p<<1
        #define rs p<<1|1
        void push_up(int p){mn(p)=_min(mn(ls),mn(rs));}
        void push_down(int p){tag(p)?tag(ls)=tag(rs)=mn(ls)=mn(rs)=tag(p):0;}
        void build(int p,int l,int r){l(p)=l,r(p)=r,(l==r)?(mn(p)=val[l]):((build(ls,l,l+r>>1),build(rs,(l+r>>1)+1,r)),push_up(p),0);}
        void modify(int p,int l,int r,int k){l>r?0:((l<=l(p)&&r(p)<=r)?mn(p)=tag(p)=k:(push_down(p),((l<=(l(p)+r(p)>>1))&&(modify(ls,l,r,k),0)),((r>(l(p)+r(p)>>1))&&(modify(rs,l,r,k),0)),push_up(p),0));}
        int query(int p,int l,int r){return (l>r)?0x7fffffff:((l<=l(p)&&r(p)<=r)?(mn(p)):(push_down(p),_min(((l<=(l(p)+r(p)>>1))?query(ls,l,r):0x7fffffff),((r>(l(p)+r(p)>>1)?query(rs,l,r):0x7fffffff)))));}
    }
    void dfs1(int p,int fat,int i=0){for(i=head[p],fa[p]=fat,dep[p]=dep[fat]+1,sz[p]=1;i;i=nxt[i])if(to[i]!=fat)dfs1(to[i],p),sz[p]+=sz[to[i]],(sz[to[i]]>sz[son[p]])&&(son[p]=to[i]);}
    void dfs2(int p,int tfa,int i=0){for(i=head[p],id[p]=++id_cnt,val[id_cnt]=a[p],top[p]=tfa,(son[p])&&(dfs2(son[p],tfa),0);i;i=nxt[i])if(to[i]!=fa[p]&&to[i]!=son[p])dfs2(to[i],to[i]);}
    void init(){dfs1(1,0),dfs2(1,1),SegmentTree::build(1,1,id_cnt);}
    void modifyChain(int u,int v,int k){
        while(top[u]^top[v])((dep[top[u]]<dep[top[v]])&&(_swap(u,v))),SegmentTree::modify(1,id[top[u]],id[u],k),u=fa[top[u]];
        ((dep[u]>dep[v])&&(_swap(u,v))),SegmentTree::modify(1,id[u],id[v],k);
    }
    int querySub(int u){return SegmentTree::query(1,id[u],id[u]+sz[u]-1);}
}
namespace MtpOnTree{
    int fa[MAXN][20],dep[MAXN];
    void dfs(int p,int fat,int i=0){
        for(fa[p][0]=fat,dep[p]=dep[fat]+1,i=1;i<=19;i++)fa[p][i]=fa[fa[p][i-1]][i-1];
        for(int i=head[p];i;i=nxt[i])if(to[i]^fat)dfs(to[i],p);
    }
    void init(){dfs(1,0);}
    int lca(int u,int v){
        if(dep[u]<dep[v])_swap(u,v);
        fd(i,19,0,1,1)if(dep[fa[u][i]]>=dep[v])u=fa[u][i];
        if(u==v)return u;
        fd(i,19,0,1,1)if(fa[u][i]^fa[v][i])u=fa[u][i],v=fa[v][i];
        return fa[u][0];
    }
    int getChainSub(int u,int v){
        fd(i,19,0,1,1)if(dep[fa[u][i]]>dep[v])u=fa[u][i];
        return u;
    }
}
int solve(int p,int pp=0,int lc=0){return (p==capt)?SLPF::querySub(1):((lc=MtpOnTree::lca(p,capt))==capt)?SLPF::querySub(p):(lc!=p)?SLPF::querySub(p):((pp=MtpOnTree::getChainSub(capt,p))*0+_min(SLPF::SegmentTree::query(1,1,SLPF::id[pp]-1),SLPF::SegmentTree::query(1,SLPF::id[pp]+SLPF::sz[pp],SLPF::id_cnt)));}
signed main(){
    n=read(),m=read();
    fu(i,1,n-1,1,1){int u=read(),v=read();add(u,v),add(v,u);}
    fu(i,1,n,1,1)a[i]=read();
    capt=read(),MtpOnTree::init(),SLPF::init();
    for(int _=1,op,u,v,w;_<=m;_++)((op=read())==1)?(capt=read()):(op==2)?(u=read(),v=read(),w=read(),SLPF::modifyChain(u,v,w),0):printf("%d\n",solve(read()));
    return 0;
}
