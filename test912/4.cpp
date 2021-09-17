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
typedef unsigned long long ull;
const int P = 19260817, MAXN = 100050;
int n,a[MAXN],m,vm;
ull ppow[MAXN];
namespace persis_seg{
	struct node{
		int ls,rs,sz,l,r;
		ull hash;
	}tr[MAXN*16<<1];
	#define l(p) tr[p].l
	#define r(p) tr[p].r
	#define ls(p) tr[p].ls
	#define rs(p) tr[p].rs
	#define sz(p) tr[p].sz
	#define hash(p) tr[p].hash
	int root[MAXN],cnt;
	void build(int &rt,int p,int l,int r,int x){//rt newer than p
		rt=++cnt;
		ls(rt)=ls(p),rs(rt)=rs(p),sz(rt)=r-l+1;
		l(rt)=l,r(rt)=r;
		if(l==r)return void(hash(rt)=hash(p)+1);
		int mid=l+r>>1;
		if(x<=mid)build(ls(rt),ls(p),l,mid,x);
		else build(rs(rt),rs(p),mid+1,r,x);
		hash(rt)=hash(ls(rt))+ppow[mid-l+1]*hash(rs(rt));
	}
	pair<ull,int> queryHash(int rt,int l,int r,int ll,int rr){
		if(!rt)return make_pair(0,r-l+1);
		if(ll<=l&&r<=rr)return make_pair(ppow[l-ll]*hash(rt),sz(rt));
		int mid=l+r>>1;
		pair<ull,int> ha1,ha2,res;
		if(ll<=mid)ha1=queryHash(ls(rt),l,mid,ll,rr);
		if(rr>mid)ha2=queryHash(rs(rt),mid+1,r,ll,rr);
		res=make_pair(ha1.first+ppow[ha1.second]*ha2.first,ha1.second+ha2.second);
		return res;
	}
	bool queryDiff(int rt1,int rt2,int rt3,int rt4,int l,int r){
	//	if(l>r)return 0;
		return queryHash(rt1,l(rt1),r(rt1),l,r).first-queryHash(rt2,l(rt2),r(rt2),l,r).first
			!= queryHash(rt3,l(rt3),r(rt3),l,r).first-queryHash(rt4,l(rt4),r(rt4),l,r).first;
	}
	int queryFirstDiff(int rt1,int rt2,int rt3,int rt4,int l,int r){
		if(l==r)return l;
		int mid=l+r>>1;
		if(queryDiff(ls(rt1),ls(rt2),ls(rt3),ls(rt4),l,mid)){
			return queryFirstDiff(ls(rt1),ls(rt2),ls(rt3),ls(rt4),l,mid);
		}
		else return queryFirstDiff(rs(rt1),rs(rt2),rs(rt3),rs(rt4),mid+1,r);
	}
	int queryLastDiff(int rt1,int rt2,int rt3,int rt4,int l,int r){
		if(l==r)return l;
		int mid=l+r>>1;
		if(queryDiff(rs(rt1),rs(rt2),rs(rt3),rs(rt4),mid+1,r)){
			return queryLastDiff(rs(rt1),rs(rt2),rs(rt3),rs(rt4),mid+1,r);
		}
		else return queryLastDiff(ls(rt1),ls(rt2),ls(rt3),ls(rt4),l,mid);
	}
}
using namespace persis_seg;
signed main(){
//	freopen("similar1.in","r",stdin);
	n=read(),m=read();
	fu(i,1,n,1,1)vm=max(vm,a[i]=read());
	ppow[0]=1ull;
	fu(i,1,vm,1,1)ppow[i]=ppow[i-1]*P;
	fu(i,1,n,1,1)
		build(root[i],root[i-1],1,vm,a[i]);
	fu(_,1,m,1,1){
		int l=read(),r=read(),ll=read(),rr=read();
		if(l==r){printf("YES\n");continue;}
		if(!queryDiff(root[r],root[l-1],root[rr],root[ll-1],1,vm))printf("YES\n");
		else {
			int pos1=queryFirstDiff(root[r],root[l-1],root[rr],root[ll-1],1,vm);
			int pos2=queryLastDiff(root[r],root[l-1],root[rr],root[ll-1],1,vm);
//			printf("%d %d ",pos1,pos2);
			if(pos1==pos2-1)printf("YES\n");
			else printf("NO\n");
//			if(!queryDiff(root[r],root[l-1],root[rr],root[ll-1],pos1+1,pos2-1))printf("YES\n");
//			else printf("NO\n");
		}
	}
}
