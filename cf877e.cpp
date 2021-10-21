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
namespace cfs{
    int cnt,head[MAXN],to[MAXN<<1],nxt[MAXN<<1];
    void add(int u,int v){nxt[++cnt]=head[u],head[u]=cnt,to[cnt]=v;}
}
int n,a[MAXN];
namespace seg{
    struct node{
        int l,r;
        int sum1,tag;
    }tr[MAXN<<2];
    int arr[MAXN];
    #define l(p) tr[p].l
    #define r(p) tr[p].r
    #define sum(p) tr[p].sum1
    #define tag(p) tr[p].tag
    #define ls p<<1
    #define rs p<<1|1
    void push_up(int p){sum(p)=sum(ls)+sum(rs);}
    void push_down(int p){
        if(tag(p)){
            tag(ls)=!tag(ls),tag(rs)=!tag(rs);
            sum(ls)=r(ls)-l(ls)+1-sum(ls),sum(rs)=r(rs)-l(rs)+1-sum(rs);
            tag(p)=0;
        }
    }
    void build(int p,int l,int r){
        l(p)=l,r(p)=r;
        if(l==r)return void(sum(p)=arr[l]);
        int mid=l+r>>1;
        build(ls,l,mid),build(rs,mid+1,r);
        push_up(p);
    }
    void modify(int p,int l,int r){
        if(l<=l(p)&&r(p)<=r){
            sum(p)=r(p)-l(p)+1-sum(p);
            tag(p)=!tag(p);
            return;
        }
        push_down(p);
        int mid=l(p)+r(p)>>1;
        if(l<=mid)modify(ls,l,r);
        if(r>mid)modify(rs,l,r);
        push_up(p);
    }
    int query(int p,int l,int r){
        if(l<=l(p)&&r(p)<=r)return sum(p);
        push_down(p);
        int mid=l(p)+r(p)>>1,res=0;
        if(l<=mid)res+=query(ls,l,r);
        if(r>mid)res+=query(rs,l,r);
        return res;
    }
}

namespace slpf{
    int dcnt,val[MAXN],id[MAXN],sz[MAXN];
    void dfs1(int p,int fa){
        sz[p]=1,id[p]=++dcnt,val[dcnt]=a[p];
        for(int i=cfs::head[p],sn;i;i=cfs::nxt[i])if((sn=cfs::to[i])!=fa){
            dfs1(sn,p);
            sz[p]+=sz[sn];
        }
    }
    void init(){
        dfs1(1,0);
        memcpy(seg::arr,val,sizeof(val));
        seg::build(1,1,n);
    }
    void modify(int u){
        seg::modify(1,id[u],id[u]+sz[u]-1);
    }
    int query(int u){
        return seg::query(1,id[u],id[u]+sz[u]-1);
    }
}
signed main(){
    n=read();
    fu(i,2,n,1,1){int u=read();cfs::add(u,i),cfs::add(i,u);}
    fu(i,1,n,1,1)a[i]=read();
    slpf::init();
    int q;scanf("%d\n",&q);
    static char c[5]={};
    while(q--){
        int u;
        scanf("%s %d\n",c,&u);
        if(c[0]=='g'){
            printf("%d\n",slpf::query(u));
        }
        else slpf::modify(u);
    }
}