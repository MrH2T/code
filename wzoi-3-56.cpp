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
const int MAXN = 100050;
int ccnt,head[MAXN],nxt[MAXN<<1],to[MAXN<<1];
void add(int u,int v){nxt[++ccnt]=head[u],head[u]=ccnt,to[ccnt]=v;}
int n,a[MAXN];
namespace seg{
    struct node{
        int ls,rs,mxcnt;
        ll mxval;
    }tr[MAXN*16<<1];
    #define ls(p) tr[p].ls
    #define rs(p) tr[p].rs
    #define mxcnt(p) tr[p].mxcnt
    #define mxval(p) tr[p].mxval
    int cnt,root[MAXN];
    void push_up(int p){
        if(mxcnt(ls(p))>mxcnt(rs(p)))mxcnt(p)=mxcnt(ls(p)),mxval(p)=mxval(ls(p));
        else if(mxcnt(ls(p))<mxcnt(rs(p)))mxcnt(p)=mxcnt(rs(p)),mxval(p)=mxval(rs(p));
        else mxcnt(p)=mxcnt(ls(p)),mxval(p)=mxval(ls(p))+mxval(rs(p));
    }
    int merge(int rt1,int rt2,int l,int r){
        if(!rt1||!rt2)return rt1+rt2;
        if(l==r){mxcnt(rt1)+=mxcnt(rt2);return rt1;}
        int mid=l+r>>1;
        ls(rt1)=merge(ls(rt1),ls(rt2),l,mid);
        rs(rt1)=merge(rs(rt1),rs(rt2),mid+1,r);
        push_up(rt1);
        return rt1;
    }
    void add(int&rt,int l,int r,int x){
        rt=++cnt;
        if(l==r){mxcnt(rt)++,mxval(rt)=x;return;}
        int mid=l+r>>1;
        if(x<=mid)add(ls(rt),l,mid,x);
        else add(rs(rt),mid+1,r,x);
        push_up(rt);
    }
}
using namespace seg;
ll ans[MAXN];
void dfs(int p,int fa){
    seg::add(root[p],1,n,a[p]);
    for(int i=head[p];i;i=nxt[i])if(to[i]!=fa){
        dfs(to[i],p);
        seg::merge(root[p],root[to[i]],1,n);
    }
    ans[p]=seg::mxval(root[p]);
}
signed main(){
    n=read();
    fu(i,1,n,1,1)a[i]=read();
    fu(i,1,n-1,1,1){int u=read(),v=read();add(u,v),add(v,u);}
    dfs(1,0);
    fu(i,1,n,1,1)printf("%lld ",ans[i]);
}
