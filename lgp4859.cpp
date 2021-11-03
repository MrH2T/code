//vj465253g

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
const int MAXN = 2050, LJC = 1e9+9;
int inv[MAXN],fac[MAXN],invfac[MAXN];
inline int C(int n,int m){
    if(n<m||m<0)return 0;
    return 1ll*fac[n]*invfac[n-m]%LJC*invfac[m]%LJC;
}
int n,k;
int a[MAXN],b[MAXN],f[MAXN][MAXN];
int ls[MAXN];
signed main(){
    n=read(),k=read();
    if(n+k&1)return printf("0\n")&0;
    fu(i,1,n,1,1)a[i]=read();sort(a+1,a+n+1);
    fu(i,1,n,1,1)b[i]=read();sort(b+1,b+n+1);
    inv[1]=fac[0]=invfac[0]=1;
    fu(i,2,n,1,1)inv[i]=1ll*(LJC-LJC/i)*inv[LJC%i]%LJC;
    fu(i,1,n,1,1)fac[i]=1ll*fac[i-1]*i%LJC,invfac[i]=1ll*invfac[i-1]*inv[i]%LJC;
    fu(i,1,n,1,1){
        ls[i]=ls[i-1];
        while(ls[i]<=n&&b[ls[i]]<a[i])ls[i]++;
        ls[i]--;
    }
    f[0][0]=1;
    fu(i,1,n,1,1){
        f[i][0]=f[i-1][0];
        fu(j,1,i,1,1)
            f[i][j]=(1ll*f[i-1][j]+1ll*max(0,ls[i]-j+1)*f[i-1][j-1]%LJC)%LJC;
    }

    int res=0,sb=(n+k)>>1;
    fu(i,sb,n,1,1){
        res=(1ll*res+(1ll*(i-sb&1?LJC-1:1)*C(i,sb)%LJC*fac[n-i]%LJC*f[n][i]%LJC)%LJC)%LJC;
    }
    printf("%d",res);
}