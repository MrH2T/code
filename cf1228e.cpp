//vj465253e

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
const int MAXN = 260, LJC = 1e9+7;
int inv[MAXN],fac[MAXN],invfac[MAXN];
inline int qp(int x,int p){
    int res=1;
    for(;p;p>>=1,x=1ll*x*x%LJC)(p&1)&&(res=1ll*res*x%LJC);
    return res;
}
inline int C(int n,int m){
    if(n<m||m<0)return 0;
    return 1ll*fac[n]*invfac[n-m]%LJC*invfac[m]%LJC;
}
int n,k;
signed main(){
    n=read(),k=read();
    inv[1]=fac[0]=invfac[0]=1;
    fu(i,2,n,1,1)inv[i]=1ll*(LJC-LJC/i)*inv[LJC%i]%LJC;
    fu(i,1,n,1,1)fac[i]=1ll*fac[i-1]*i%LJC,invfac[i]=1ll*invfac[i-1]*inv[i]%LJC;
    int ans=0;
    fu(i,0,n,1,1){
        fu(j,0,n,1,1){
            ans=(1ll*ans+(1ll*((i+j&1)?LJC-1:1)*1ll*C(n,i)%LJC*C(n,j)%LJC
                *qp(k-1,n*(i+j)-i*j)%LJC*qp(k,n*n-n*(i+j)+i*j)%LJC)%LJC)%LJC;
        }
    }
    printf("%d",ans);
}
