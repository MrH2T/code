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
int n,m;
namespace CFStar{
    int cnt,head[MAXN],to[MAXN<<1],nxt[MAXN<<1];
    void add(int u,int v){nxt[++cnt]=head[u],head[u]=cnt,to[cnt]=v;}
}
namespace SegmentTree{
    struct node{int l,r,sum,tag;}tr[MAXN<<2];//sum is count of 1
    #define l(p) tr[p].l
    #define r(p) tr[p].r
    #define ls p<<1
    #define rs p<<1|1
    #define sum(p) tr[p].sum
    #define tag(p) tr[p].tag
    void push_up(int p){sum(p)=sum(ls)+sum(rs);}
    void push_down(int p){
        if(tag(p)){
            sum(ls)=(r(ls)-l(ls)+1)*(2-tag(p));
            sum(rs)=(r(rs)-l(rs)+1)*(2-tag(p));
            tag(ls)=tag(rs)=tag(p);
        }
        tag(p)=0;
    }
    void build(int p,int l,int r){
        l(p)=l,r(p)=r;
        if(l==r)return;
        build(ls,l,l+r>>1),build(rs,(l+r>>1)+1,r);
        push_up(p);
    }
    int query(int p,int l,int r){ // return count of 1 from l to r
        if(l<=l(p)&&r(p)<=r)return sum(p);
        push_down(p);
        int res=0,mid=l(p)+r(p)>>1;
        if(l<=mid)res+=query(ls,l,r);
        if(r>mid)res+=query(rs,l,r);
        return res;
    }
    void modify(int p,int l,int r,int typ){
        if(l<=l(p)&&r(p)<=r){
            tag(p)=typ;
            sum(p)=(r(p)-l(p)+1)*(2-typ);
            return ;
        }
        push_down(p);
        int mid=l(p)+r(p)>>1;
        if(l<=mid)modify(ls,l,r,typ);
        if(r>mid)modify(rs,l,r,typ);
        push_up(p);
    }
}
namespace SLPF{
    int sz[MAXN],fa[MAXN],dep[MAXN],son[MAXN];
    int id[MAXN],top[MAXN],cntN;
    void dfs1(int p,int fat,int dp){
        dep[p]=dp,fa[p]=fat,sz[p]=1;
        int mxson=-1;
        for(int i=CFStar::head[p],so;i;i=CFStar::nxt[i])if((so=CFStar::to[i])!=fat){
            dfs1(so,p,dp+1);
            sz[p]+=sz[so];
            if(sz[so]>mxson)mxson=sz[so],son[p]=so;
        }
    }
    void dfs2(int p,int tpf){
        id[p]=++cntN;
        top[p]=tpf;
        if(!son[p])return;
        dfs2(son[p],tpf);
        for(int i=CFStar::head[p],so;i;i=CFStar::nxt[i])if((so=CFStar::to[i])!=fa[p]&&so!=son[p]){
            dfs2(so,so);
        }
    }
    void init(){
        dfs1(1,0,1);
        dfs2(1,1);
        SegmentTree::build(1,1,n);
    }
    void unsSub(int p){
        SegmentTree::modify(1,id[p],id[p]+sz[p]-1,2);
    }
    void queryUns(int p){
        int one=SegmentTree::query(1,id[p],id[p]+sz[p]-1);
        printf("%d\n",one);
        unsSub(p);
    }
    void queryIns(int p){
        int ans=0;int x=1,y=p;
        while(top[x]!=top[y]){
            if(dep[top[x]]<dep[top[y]])swap(x,y);
            (ans+=(id[x]-id[top[x]]+1)-SegmentTree::query(1,id[top[x]],id[x]));
            SegmentTree::modify(1,id[top[x]],id[x],1);
            x=fa[top[x]];
        }
        if(dep[x]>dep[y])swap(x,y);
        ans+=(id[y]-id[x]+1)-SegmentTree::query(1,id[x],id[y]);
        SegmentTree::modify(1,id[x],id[y],1);
        printf("%d\n",ans);
    }
}
string s;
signed main(){
    n=read();
    fu(i,2,n,1,1){
        int x=read()+1;
        CFStar::add(x,i),CFStar::add(i,x);
    }
    SLPF::init();
    m=read();
    fu(i,1,m,1,1){
        int x;
        cin>>s>>x;x++;
        if(s=="uninstall")SLPF::queryUns(x);
        else SLPF::queryIns(x);
    }
}
