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
int T;
int n,m;

signed main(){
	T=read();
	while(T--){
		n=read(),m=read();
		int sqn=sqrt(n);
		
		fu(i,1,sqn,1,1){
		//	if(i*i==n)continue;
			if(n%i==0){
				if(2LL*(i+n/i+2)<=m){
					printf("Good\n");
					goto fk;
				}
			}
		}
		printf("Miss\n");
		fk:;
	}
}

