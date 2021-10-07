#include<bits/stdc++.h>
#define int __int128
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
int n,p;
signed main(){
	T=read();
	while(T--){
		n=read(),p=read();
		if(p==1){
			printf("0\n");
			continue;
		}
		int op=1;
		int ppow=1;
		unsigned long long ans=0;
		while(ppow<=n){
			ans+=op*n/ppow;
			if(ppow>n/p)break;
			ppow=ppow*p;
			op=-op;
		}
		printf("%llu\n",ans);
	}
}

