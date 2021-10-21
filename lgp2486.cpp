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
inline void f_swap(int& u,int& v){int t=u;u=v,v=t;}
namespace cfs{
    int cnt,head[MAXN],to[MAXN<<1],nxt[MAXN<<1];
    void add(int u,int v){
        nxt[++cnt]=head[u],head[u]=cnt,to[cnt]=v;
    }
}
namespace seg{
    struct tri{
        int sum,lcol,rcol;
        tri(){sum=lcol=rcol=0;}
        tri(int s,int l,int r):sum(s),lcol(l),rcol(r){}
        friend bool operator!(tri a){return !a.sum;}
        friend tri operator+(tri a,tri b){return tri(a.sum+b.sum,a.lcol+b.lcol,a.rcol+b.rcol);}
    };
    tri inv(tri x){
        tri res=x;
        f_swap(res.lcol,res.rcol);
        return res;
    }
    tri merge(tri l,tri r){
        if(!l||!r)return l+r;
        tri res;
        res.lcol=l.lcol,res.rcol=r.rcol,res.sum=l.sum+r.sum-(l.rcol==r.lcol);
        return res;
    }
    struct node{
        int l,r;
        int lcol,rcol,sum,tag;
    }tr[MAXN<<2];
    int arr[MAXN];
    #define l(p) tr[p].l
    #define r(p) tr[p].r
    #define lcol(p) tr[p].lcol
    #define rcol(p) tr[p].rcol
    #define sum(p) tr[p].sum
    #define tag(p) tr[p].tag
    #define ls p<<1
    #define rs p<<1|1
    void push_up(int p){
        lcol(p)=lcol(ls),rcol(p)=rcol(rs);
        sum(p)=sum(ls)+sum(rs)-(rcol(ls)==lcol(rs));
    }
    void push_down(int p){
        if(tag(p)){
            lcol(ls)=rcol(ls)=lcol(rs)=rcol(rs)=tag(p);
            sum(ls)=sum(rs)=1;
            tag(ls)=tag(rs)=tag(p);
            tag(p)=0;
        }
    }
    void build(int p,int l,int r){
        l(p)=l,r(p)=r;
        if(l==r){
            lcol(p)=rcol(p)=arr[l];
            sum(p)=1;
            return;
        }
        int mid=l+r>>1;
        build(ls,l,mid),build(rs,mid+1,r);
        push_up(p);
    }
    void modify(int p,int l,int r,int k){
        if(l<=l(p)&&r(p)<=r){
            sum(p)=1,lcol(p)=rcol(p)=tag(p)=k;
            return;
        }
        push_down(p);
        int mid=l(p)+r(p)>>1;
        if(l<=mid)modify(ls,l,r,k);
        if(r>mid)modify(rs,l,r,k);
        push_up(p);
    }
    tri query(int p,int l,int r){
        if(l<=l(p)&&r(p)<=r)return tri(sum(p),lcol(p),rcol(p));
        push_down(p);
        int mid=l(p)+r(p)>>1;
        tri lt,rt,res;
        if(l<=mid)lt=query(ls,l,r);
        if(r>mid)rt=query(rs,l,r);
        res=merge(lt,rt);
        return res;
    }
}
int n,m,a[MAXN];
namespace slpf{
    int dep[MAXN],top[MAXN],fa[MAXN],son[MAXN],sz[MAXN];
    int dcnt,val[MAXN],dfn[MAXN];
    void dfs1(int p,int fat){
        fa[p]=fat,dep[p]=dep[fat]+1;
        sz[p]=1;
        for(int i=cfs::head[p],sn;i;i=cfs::nxt[i])if((sn=cfs::to[i])!=fat){
            dfs1(sn,p);
            sz[p]+=sz[sn];
            if(sz[sn]>sz[son[p]])son[p]=sn;
        }
    }
    void dfs2(int p,int tfa){
        dfn[p]=++dcnt;
        val[dcnt]=a[p];
        top[p]=tfa;
        if(!son[p])return;
        dfs2(son[p],tfa);
        for(int i=cfs::head[p],sn;i;i=cfs::nxt[i])if((sn=cfs::to[i])!=fa[p]&&sn!=son[p]){
            dfs2(sn,sn);
        }
    }
    void init(){
        dfs1(1,0),dfs2(1,1);
        memcpy(seg::arr,val,sizeof(val));
        seg::build(1,1,n);
    }
    void modifyChain(int u,int v,int k){
        while(top[u]!=top[v]){
            if(dep[top[u]]<dep[top[v]])f_swap(u,v);
            seg::modify(1,dfn[top[u]],dfn[u],k);
            u=fa[top[u]];
        }
        if(dep[u]>dep[v])f_swap(u,v);
        seg::modify(1,dfn[u],dfn[v],k);
    }
    int queryChain(int u,int v){
        seg::tri ans[2]={};int sd=0;
        while(top[u]!=top[v]){
            if(dep[top[u]]<dep[top[v]])f_swap(u,v),sd^=1;
            seg::tri res=seg::query(1,dfn[top[u]],dfn[u]);
            if(!ans[sd])ans[sd]=res;
            else {
                ans[sd]=seg::merge(res,ans[sd]);
            }
            u=fa[top[u]];
        }
        if(dep[u]>dep[v])f_swap(u,v),sd^=1;
        seg::tri res=seg::query(1,dfn[u],dfn[v]);
        seg::tri res1=seg::merge(res,ans[sd^1]);
        seg::tri res2=seg::merge(inv(ans[sd]),res1);
        return res2.sum;
    }
}

signed main(){
    n=read(),m=read();
    fu(i,1,n,1,1)a[i]=read();
    fu(i,1,n-2,1,1){int u=read(),v=read();cfs::add(u,v),cfs::add(v,u);}
    int u,v;scanf("%d %d\n",&u,&v);cfs::add(u,v),cfs::add(v,u);
    slpf::init();
    fu(i,1,m,1,1){
        char op;scanf("%c",&op);
        if(op=='C'){
            int a=read(),b=read(),c;
            scanf("%d\n",&c);
            slpf::modifyChain(a,b,c);
        }
        else {
            int a=read(),b;scanf("%d\n",&b);
            printf("%d\n",slpf::queryChain(a,b));
        }
    }
}