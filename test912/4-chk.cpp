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
int tmp1[1050],tmp2[1050];
int n,a[1050];
signed main(){freopen("similarchk.in","r",stdin);
	n=read();
	fu(i,1,n,1,1){
	a[i]=read();}
	while(1){
		int l=read(),r=read(),ll=read(),rr=read();
		fu(i,l,r,1,1)tmp1[i-l+1]=a[i];
		fu(i,ll,rr,1,1)tmp2[i-ll+1]=a[i];
		sort(tmp1+1,tmp1+r-l+2);
		sort(tmp2+1,tmp2+r-l+2);
		fu(i,1,r-l+1,1,1)printf("%d %d\n",tmp1[i],tmp2[i]);
	}
}

