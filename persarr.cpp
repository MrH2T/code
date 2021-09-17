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
struct node{
    int ls,rs,val;
}tr[MAXN*20*2];
#define ls(p) tr[p].ls
#define rs(p) tr[p].rs
#define val(p) tr[p].val
int cnt,a[MAXN];
void build(int &rt,int l,int r){
	rt=++cnt;
	if(l==r)return void(val(rt)=a[l]);
	int mid=l+r>>1;
	build(ls(rt),l,mid);
	build(rs(rt),mid+1,r);
}
void modify(int &rt,int p,int l,int r,int x,int k){
    rt=++cnt;
    ls(rt)=ls(p),rs(rt)=rs(p);
    if(l==r){
        val(rt)=k;
        return;
    }
    int mid=l+r>>1;
    if(x<=mid)modify(ls(rt),ls(p),l,mid,x,k);
    else modify(rs(rt),rs(p),mid+1,r,x,k);
}
int query(int rt,int l,int r,int x){
    if(l==r)return val(rt);
    int mid=l+r>>1;
    if(x<=mid)return query(ls(rt),l,mid,x);
    else return query(rs(rt),mid+1,r,x);
}
int n,m,root[MAXN];
signed main(){
    n=read(),m=read();
    fu(i,1,n,1,1)a[i]=read();
    build(root[0],1,n);
    fu(i,1,m,1,1){
        int v=read(),op=read(),x=read();
        if(op==1)modify(root[i],root[v],1,n,x,read());
        else root[i]=root[v],printf("%d\n",query(root[v],1,n,x));
    }
}
