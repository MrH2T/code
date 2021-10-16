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
int a,b;
signed main(){
	while(1){
		a=read();if(!~a)return 0;
		b=read();
		if((a==0&&b==0)||((a%5==2||a%5==3)&&(b%5==2||b%5==3)))puts("SheepDaddy");
		else puts("MengMeng");
	}
}

