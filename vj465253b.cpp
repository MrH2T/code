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
const int MAXN = 2550,LJC = 1e9+7;
inline int qp(int x,int p){
    int res=1;
    for(;p;p>>=1,x=1ll*x*x%LJC)(p&1)&&(res=1ll*res*x%LJC);
    return res;
}
inline int inv(int x){
    return qp(x,LJC-2);
}
int fac[MAXN];
int n,k;
signed main(){
    n=read(),k=read();
    fac[0]=1;fu(i,1,2500,1,1)fac[i]=1ll*fac[i-1]*i%LJC;
    int res=0;
    fu(i,1,k,1,1){
        res=(1ll*res+(1ll*(k-i&1?LJC-1:1)*fac[k]%LJC*inv(fac[i])%LJC*inv(fac[k-i])%LJC*i%LJC*qp(i-1,n-1)%LJC)%LJC)%LJC;
    }
    printf("%d",res);
}