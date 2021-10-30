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
const int MAXN = 1000050, LJC = 1e9+7;
int n,k;
inline int qpow(int x,int p,int MOD=LJC){
    int res=1;
    for(;p;p>>=1,x=1LL*x*x%MOD)(p&1)&&(res=1LL*res*x%MOD);
    return res;
}
inline int inv(int x){return qpow(x,LJC-2);}
int fac[MAXN];
signed main(){
    n=read(),k=read();
    fac[0]=1;
    fu(i,1,n,1,1)fac[i]=1LL*fac[i-1]*i%LJC;
    int res=0;
    fu(i,k,n,1,1){
        res=(1LL*res+1LL*((i-k&1)?LJC-1:1)*(fac[n])%LJC*inv(fac[n-i])%LJC
            *inv(fac[i-k])%LJC*inv(fac[k])%LJC*(1LL*qpow(2,qpow(2,n-i,LJC-1))-1+LJC)%LJC)%LJC;
    }
    printf("%d",res);
}