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
const int MAXN = 1050;
int n,a[MAXN][MAXN],f[MAXN][MAXN],s[MAXN][MAXN];
signed main(){
	int T=read();
	while(T--){
		n=read();
		fu(i,1,n,1,1)fu(j,1,n,1,1)a[i][j]=read();
		fu(i,1,n,1,1)fu(j,1,n,1,1)s[i][j]=s[i][j-1]+a[i][j];
		fu(i,1,n,1,1)fu(j,1,n,1,1)s[i][j]+=s[i-1][j];
		fu(i,1,n,1,1){
			fu(j,1,n,1,1){
				bool win=0;
				if((s[i][j]-s[i-1][j])%2==0)win|=(!f[i-1][j]);
				if((s[i][j]-s[i][j-1])%2==0)win|=(!f[i][j-1]);
				f[i][j]=win;
			}
		}
		printf("%s\n",f[n][n]?"W":"L");
	}
}

