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
const int MOD = 998244353,MAXN=2050;
int qpow(int x,int p){
    int res=1;
    for(;p;p>>=1,x=x*x%MOD)(p&1)&&(res=res*x%MOD);
    return res;
}
int inv(int x){
    return qpow(x,MOD-2);
}
int n,k;
int x[MAXN],y[MAXN];
int res=0;
signed main(){
    n=read(),k=read();
    fu(i,1,n,1,1)x[i]=read(),y[i]=read();
    fu(i,1,n,1,1){
        int tmp=1;
        fu(j,1,n,1,1)if(i!=j){
            tmp=tmp*(k-x[j])%MOD*inv(x[i]-x[j])%MOD;
        }
        res=(res+y[i]*tmp%MOD)%MOD;
    }
    printf("%lld",(res%MOD+MOD)%MOD);
}