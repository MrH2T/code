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
const int MAXN = 100050;
int n,m,a[MAXN],op[MAXN],lb[MAXN],rb[MAXN],q;
int b[MAXN];
struct nd{int l,r,one,tag;}tr[MAXN<<2];
#define ls p<<1
#define rs p<<1|1
#define l(p) tr[p].l
#define r(p) tr[p].r
#define one(p) tr[p].one
#define tag(p) tr[p].tag
#define len(p) (r(p)-l(p)+1)
void push_up(int p){
    one(p)=one(ls)+one(rs);
}
void push_down(int p){
    if(!~tag(p))return;
    // printf("%d:%d\n",p,tag(p));
    // printf("fuck\n");
    one(ls)=len(ls)*tag(p);
    one(rs)=len(rs)*tag(p);
    tag(ls)=tag(rs)=tag(p);
    tag(p)=-1;
}
void build(int p,int l,int r){
    l(p)=l,r(p)=r,tag(p)=-1;
    if(l==r){one(p)=b[l];return;}
    int mid=l+r>>1;
    build(ls,l,mid),build(rs,mid+1,r);
    push_up(p);
}
void modify(int p,int l,int r,int k){
    if(l>r)return;
    if(l<=l(p)&&r(p)<=r){
        one(p)=len(p)*k;
        tag(p)=k;
        return;
    }
    push_down(p);
    int mid=l(p)+r(p)>>1;
    if(l<=mid)modify(ls,l,r,k);
    if(r>mid)modify(rs,l,r,k);
    push_up(p);
}
int query(int p,int l,int r){
    if(l>r)return 0;
    if(l<=l(p)&&r(p)<=r)return one(p);
    push_down(p);
    int mid=l(p)+r(p)>>1,res=0;
    if(l<=mid)res+=query(ls,l,r);
    if(r>mid)res+=query(rs,l,r);
    return res;
}

#define output fu(j,1,n,1,1)printf("%d ",query(1,j,j));putchar('\n');
bool check(int x){
    // printf("%d:  :\n",x);
    fu(i,1,n,1,1)if(a[i]>=x)b[i]=1;else b[i]=0;
    build(1,1,n);
    // output;
    fu(i,1,m,1,1){
        int ones=query(1,lb[i],rb[i]);
        modify(1,lb[i],rb[i],0);
        if(op[i]==0)modify(1,rb[i]-ones+1,rb[i],1);
        else modify(1,lb[i],lb[i]+ones-1,1);
        // output;
    }
    // output;
    return query(1,q,q);
} 
signed main(){
    n=read(),m=read();
    fu(i,1,n,1,1)a[i]=read();
    fu(i,1,m,1,1)op[i]=read(),lb[i]=read(),rb[i]=read();
    q=read();
    int l=1,r=n+1;
    int ans=0;
    while(l<r){
        int mid=l+r>>1;
        if(check(mid))ans=mid,l=mid+1;
        else r=mid;
    }
    printf("%d",ans);
}