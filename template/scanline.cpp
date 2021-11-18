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
const int MAXN = 1000050;
struct Line{
    int x,l,r,k;
}line[MAXN<<1];
int val[MAXN<<1];
struct node{
    int sum,len;
    int l,r;
}tr[MAXN<<2];
#define sum(p) tr[p].sum
#define len(p) tr[p].len
#define l(p) tr[p].l
#define r(p) tr[p].r
#define ls p<<1
#define rs p<<1|1
void build(int p,int l,int r){
    l(p)=l,r(p)=r;
    if(l==r)return;
    int mid=l+r>>1;
    build(ls,l,mid),build(rs,mid+1,r);

}
void push_up(int p){
    if(sum(p))len(p)=val[r(p)+1]-val[l(p)];
    else len(p)=len(ls)+len(rs);
}
void modify(int p,int ll,int rr,int k){
    if(val[r(p)+1]<=ll||val[l(p)]>=rr)return;
    if(ll<=val[l(p)]&&val[r(p)+1]<=rr)return sum(p)+=k,push_up(p);
    modify(ls,ll,rr,k);
    modify(rs,ll,rr,k);
    push_up(p);
}
int n,v;
signed main(){
    n=read();
    fu(i,1,n,1,1){
        int x=read(),y=read(),xx=read(),yy=read();
        val[2*i-1]=y,val[2*i]=yy;
        line[2*i-1]=(Line){x,y,yy,1};
        line[2*i]=(Line){xx,y,yy,-1};
    }
    sort(val+1,val+2*n+1);
    v=unique(val+1,val+2*n+1)-val-1;
    sort(line+1,line+2*n+1,[](Line a,Line b){return a.x<b.x;});
    long long ans=0;
    build(1,1,v-1);
    fu(i,1,2*n-1,1,1){
        modify(1,line[i].l,line[i].r,line[i].k);
        ans+=1ll*(line[i+1].x-line[i].x)*len(1);
    }
    printf("%lld\n",ans);
}