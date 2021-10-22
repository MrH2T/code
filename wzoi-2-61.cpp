#include<bits/stdc++.h>
#define rint register int
#define fu(i,a,b,d,c) for(rint i=a;i<=b&&c;i+=d)
#define fd(i,a,b,d,c) for(rint i=a;i>=b&&c;i-=d)
using namespace std;
inline int read(){
    char c=0,f=1;int num=0;
    while(c<'0'||c>'9')((c=getchar())=='-')&&(f=-f);
    while(c>='0'&&c<='9')num=(num<<1)+(num<<3)+(c^48),c=getchar();
    return num*f;
}
const int MAXN = 200050;
struct que{
    int l,r,id;
}q[MAXN];
struct seg{
    int mn;
}tr[MAXN<<2];
#define mn(p) tr[p].mn
#define ls p<<1
#define rs p<<1|1
void push_up(int p){mn(p)=min(mn(ls),mn(rs));}
void modify(int p,int l,int r,int x,int k){
    if(l==r)return void(mn(p)=k);
    int mid=l+r>>1;
    if(x<=mid)modify(ls,l,mid,x,k);
    else modify(rs,mid+1,r,x,k);
    push_up(p);
}
int query(int p,int l,int r,int x){
    if(l==r)return l;
    int mid=l+r>>1;
    if(mn(ls)<x)return query(ls,l,mid,x);
    else return query(rs,mid+1,r,x);
}
int n,m,a[MAXN],ans[MAXN];

signed main(){
    n=read(),m=read();
    fu(i,1,n,1,1)a[i]=read();
    fu(i,1,m,1,1)q[i].l=read(),q[i].r=read(),q[i].id=i;
    sort(q+1,q+m+1,[](que a,que b)->bool{return a.r<b.r;});
    int ptr=0;
    fu(i,1,m,1,1){
        while(ptr<q[i].r){
            ++ptr;
            if(a[ptr]<n)modify(1,0,n-1,a[ptr],ptr);
        }
        ans[q[i].id]=query(1,0,n-1,q[i].l);
    }
    fu(i,1,m,1,1)printf("%d\n",ans[i]);
}