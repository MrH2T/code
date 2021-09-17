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
const int MAXN = 100050; 
bool cmp(int a,int b){
	return (a)>(b);
}
int n;
int ji[MAXN],ou[MAXN];
int ans;
signed main(){
	n=read();
	fu(i,1,n,1,1){
		int k=read();
		if(abs(k)%2==1)ou[++ou[0]]=k;
		else ji[++ji[0]]=k;
		ans+=k;
	}
	sort(ji+1,ji+ji[0]+1,cmp);
	sort(ou+1,ou+ou[0]+1,cmp);
	int ptr1=1,ptr2=1,ptr11=ji[0],ptr22=ou[0];
	int i=1;
	for(;i<=n&&ptr1<=ptr11&&ptr2<=ptr22;i++){
		if(i%2){
			int v1=(ji[ptr1])*pow(-1,i+1+ji[ptr1]);
			int v2=(ou[ptr22])*pow(-1,i+1+ou[ptr22]);
			if(v1>v2){
				ans+=v1*(n-i);
				ptr1++;
			}
			else{
				ans+=v2*(n-i);
				ptr22--;
			}
		}
		else{
			int v1=(ji[ptr11])*pow(-1,i+1+ji[ptr11]);
			int v2=(ou[ptr2])*pow(-1,i+1+ou[ptr2]);
			if(v1>v2){
				ans+=v1*(n-i);
				ptr11--;
			}
			else{
				ans+=v2*(n-i);
				ptr2++;
			}
		}
	}
	if(ptr1<=ptr11){
		for(;i<=n;i++){
			int v1=(ji[ptr1])*pow(-1,ji[ptr1]+i+1),
				v2=(ji[ptr11])*pow(-1,ji[ptr11]+i+1);
			if(v1>v2)ans+=v1*(n-i),ptr1++;
			else ans+=v2*(n-i),ptr11--;
		}
	}
	if(ptr2<=ptr22){
		for(;i<=n;i++){
			int v1=(ou[ptr2])*pow(-1,ou[ptr2]+i+1),
				v2=(ou[ptr22])*pow(-1,ou[ptr22]+i+1);
			if(v1>v2)ans+=v1*(n-i),ptr2++;
			else ans+=v2*(n-i),ptr22--;
		}
	}
	printf("%lld",ans);
}

