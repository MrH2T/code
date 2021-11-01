//vj465253f

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
const int MAXN =  1e6+50, LJC = 998244353; 
inline int qp(int x,int p){
    int res=1;
    for(;p;p>>=1,x=1ll*x*x%LJC)(p&1)&&(res=1ll*res*x%LJC);
    return res;
}
int inv[MAXN],fac[MAXN],invfac[MAXN];
inline int C(int n,int m){
    if(n<m||m<0)return 0;
    return 1ll*fac[n]*invfac[n-m]%LJC*invfac[m]%LJC;
}
int n,pow3[MAXN],pow3n[MAXN];
signed main(){
    n=read();
    inv[1]=fac[0]=pow3[0]=pow3n[0]=invfac[0]=1;
    fu(i,2,1e6,1,1)inv[i]=1ll*(LJC-LJC/i)*inv[LJC%i]%LJC;
    fu(i,1,1e6,1,1)fac[i]=1ll*fac[i-1]*i%LJC,invfac[i]=1ll*invfac[i-1]*inv[i]%LJC;
    int _3n=qp(3,n);
    fu(i,1,n,1,1)pow3[i]=1ll*pow3[i-1]*3%LJC,pow3n[i]=1ll*pow3n[i-1]*_3n%LJC;
    int full=qp(3,1ll*n*n%(LJC-1));
    int res1=full,res2=0;
    fu(i,1,n,1,1){
        res1=(1ll*res1+2ll*(i&1?LJC-1:1)*pow3[i]%LJC*C(n,i)%LJC*pow3n[n-i]%LJC)%LJC;
    }
    fu(i,1,n,1,1){
        res2=(1ll*res2+(1ll*(i&1?LJC-1:1)*C(n,i)%LJC*((1ll*qp((pow3[n-i]-1+LJC)%LJC,n)-
            pow3n[n-i])%LJC+LJC)%LJC)%LJC)%LJC;
    }
    res2=3ll*res2%LJC;
    printf("%d",((1ll*full-res1-res2)%LJC+LJC)%LJC);
}