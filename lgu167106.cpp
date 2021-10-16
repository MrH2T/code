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
const int MAXN=500050;
struct SegTree{
	int l,r;
	int mx,mn;
	int tag;
}tr[MAXN<<2];
int n,q,a[MAXN];
inline int max_(int a,int b){return a>b?a:b;}
inline int min_(int a,int b){return a<b?a:b;}
#define l(p) tr[p].l
#define r(p) tr[p].r
#define mx(p) tr[p].mx
#define mn(p) tr[p].mn
#define tag(p) tr[p].tag
#define ls p<<1
#define rs p<<1|1
void push_up(int p){
	mx(p)=max_(mx(ls),mx(rs));
	mn(p)=min_(mn(ls),mn(rs));
}
void push_down(int p){
	if(tag(p)==2e9){
		mx(ls)=-2e9;mx(rs)=-2e9;
		mn(ls)=2e9;mn(rs)=2e9;
		tag(ls)=tag(rs)=2e9;
		tag(p)=0;
		return;
	}
	if(tag(p)){
		mx(ls)=mn(ls)=mx(rs)=mn(rs)=tag(p);
		tag(ls)=tag(rs)=tag(p);
		tag(p)=0;
		return;
	}
}
void build(int p,int l,int r){
	if(l==r){
		mx(p)=mn(p)=a[l];
		l(p)=r(p)=l;
		return ;
	}
	int mid=l+r>>1;
	build(ls,l,mid);
	build(rs,mid+1,r);
	l(p)=l,r(p)=r;tag(p)=0;
	push_up(p);
}
void modify(int p,int l,int r,int k){
	if(l<=l(p)&&r(p)<=r){
		tag(p)=k;
		if(k==2e9)mx(p)=-2e9,mn(p)=2e9;
		else mx(p)=mn(p)=k;
		return;
	}
	push_down(p);
	int mid=l(p)+r(p)>>1;
	if(l<=mid)modify(ls,l,r,k);
	if(r>mid)modify(rs,l,r,k);
	push_up(p);
}
int queryMax(int p,int l,int r){
	if(l<=l(p)&&r(p)<=r)return mx(p);
	push_down(p);
	int res = -2e9;
	int mid=l(p)+r(p)>>1;
	if(l<=mid)res=max_(res,queryMax(ls,l,r));
	if(r>mid)res=max_(res,queryMax(rs,l,r));
	return res;
}
int queryMin(int p,int l,int r){
	if(l<=l(p)&&r(p)<=r)return mn(p);
	push_down(p);
	int res = 2e9;
	int mid=l(p)+r(p)>>1;
	if(l<=mid)res=min_(res,queryMin(ls,l,r));
	if(r>mid)res=min_(res,queryMin(rs,l,r));
	return res;
}
signed main(){
//	freopen("data.in","r",stdin);
//	freopen("data.ans","w",stdout);
	n=read();
	fu(i,1,n,1,1)a[i]=read();
	build(1,1,n);
	q=read();
	fu(i,1,q,1,1){
		int op=read(),l=read(),r=read(),k=read();
		if(op==1){
			int mxx=queryMax(1,l,r),mnn=queryMin(1,l,r);
			if(mxx==-2e9||mnn==2e9){
				printf("fa1se\n");
				continue;
			}
			if(mxx==mnn&&mxx==k){
				printf("true\n");
				modify(1,l,r,2e9);
			}
			else printf("fa1se\n");
		}
		if(op==2){
			modify(1,l,r,k);
		}
	}
	fu(i,1,n,1,1){
		int val=queryMax(1,i,i);
		printf("%d ",val==-2e9?0:val);
	}
}
