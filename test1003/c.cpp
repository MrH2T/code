#include<bits/stdc++.h>
#define int long long
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
const int MAXN = 3e6+50, MAXQ = 3e5+50;
struct qry{
	int x,t;
}qu[MAXQ];
int n,q,a[MAXN],ans[MAXN];
signed main(){
	n=read(),q=read();
	fu(i,1,n,1,1)a[i]=read();
	fu(i,1,q,1,1)qu[i]=(qry){read(),i};
	sort(qu+1,qu+q+1,[](qry a,qry b)->bool{return a.x<b.x;});
	
	fu(i,1,n,1,1){
		
	}
	
}

