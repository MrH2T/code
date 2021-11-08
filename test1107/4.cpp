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
const int MAXN = 1000050 ,LJC = 998244353;
int inv[MAXN],fac[MAXN],invfac[MAXN];
int ipow[MAXN];
int prm[MAXN],cnt,vis[MAXN];
inline int qp(int x,int p){
    int res=1;
    for(;p;p>>=1,x=1ll*x*x%LJC)(p&1)&&(res=1ll*res*x%LJC);
    return res;
}
inline int C(int n,int m){
    if(n<m||m<0)return 0;
    return 1ll*fac[n]*invfac[n-m]%LJC*invfac[m]%LJC;
}
int n,k,sum;
signed main(){
    n=read(),k=read();
    fu(i,1,n,1,1)sum=(1ll*sum+read())%LJC;
    inv[1]=fac[0]=invfac[0]=1;
    fu(i,2,n,1,1)inv[i]=1ll*(LJC-LJC/i)*inv[LJC%i]%LJC;
    fu(i,1,n,1,1)fac[i]=1ll*fac[i-1]*i%LJC,invfac[i]=1ll*invfac[i-1]*inv[i]%LJC;
    //init i^n and i^{n-1}
    ipow[1]=1;
    fu(i,2,n,1,1){
        if(!vis[i]){
            prm[++cnt]=i;
            ipow[i]=qp(i,n);
        }
        for(int j=1;j<=cnt&&1ll*i*prm[j]<=n;j++){
            ipow[i*prm[j]]=1ll*ipow[i]*ipow[prm[j]]%LJC;
            vis[i*prm[j]]=1;
            if(i%prm[j]==0)break;
        }
    }
    int coef=0;
    //get {n,k}
    int c1=0;
    fu(i,1,k,1,1){
        c1=(1ll*c1+(1ll*(k-i&1?LJC-1:1)*C(k,i)%LJC*ipow[i]%LJC)%LJC)%LJC;
    }
    //get {n-1,k}
    int c2=0;
    fu(i,1,k,1,1){
        c2=(1ll*c2+(1ll*(k-i&1?LJC-1:1)*C(k,i)%LJC*ipow[i]%LJC*inv[i]%LJC)%LJC)%LJC;
    }
    coef=(1ll*c1+1ll*(n-1)*c2%LJC)%LJC*invfac[k]%LJC;
    printf("%d",1ll*coef*sum%LJC);
}
