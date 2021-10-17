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
const int MOD = 1e9+7, MAXN = 300050;
inline int qpow(int x,int p){
	int res=1;
	for(;p;p>>=1,x=x*x%MOD)if(p&1)res=res*x%MOD;
	return res;
}
inline int inv(int x){
	return qpow(x,MOD-2);
}
int t,p;
int fac[MAXN];
signed main(){
	t=read(),p=read();
	if(t<abs(p)){
		printf("0\n");
		return 0;
	}
	fac[0]=1;
	fu(i,1,2*t,1,1)fac[i]=fac[i-1]*i%MOD;
	printf("%lld",1ll*fac[2*t]*inv(fac[t+p])%MOD*inv(fac[t-p])%MOD*qpow(inv(4),t)%MOD);
	return 0;
}