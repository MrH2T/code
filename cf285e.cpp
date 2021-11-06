//vj465253h

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
const int MAXN = 1050, LJC= 1e9+7;
int n,m;
int inv[MAXN],fac[MAXN],invfac[MAXN];
inline int C(int n,int m){
    if(n<m||m<0)return 0;
    return 1ll*fac[n]*invfac[n-m]%LJC*invfac[m]%LJC;
}
int f[MAXN][MAXN][2][2], h[MAXN];
signed main(){
    n=read(),m=read();
    inv[1]=fac[0]=invfac[0]=1;
    fu(i,2,n,1,1)inv[i]=1ll*(LJC-LJC/i)*inv[LJC%i]%LJC;
    fu(i,1,n,1,1)fac[i]=1ll*fac[i-1]*i%LJC,invfac[i]=1ll*invfac[i-1]*inv[i]%LJC;
    f[1][0][0][0]=f[1][1][0][1]=1;
    fu(i,2,n-1,1,1){
        f[i][0][0][0]=1;
        fu(j,1,i,1,1){
            f[i][j][0][0]=(1ll*f[i][j][0][0]+f[i-1][j-1][0][0]+f[i-1][j][0][0]+f[i-1][j][1][0])%LJC;
            f[i][j][0][1]=(1ll*f[i][j][0][1]+f[i-1][j-1][0][0]+f[i-1][j-1][1][0])%LJC;
            f[i][j][1][0]=(1ll*f[i][j][1][0]+f[i-1][j-1][0][1]+f[i-1][j][0][1]+f[i-1][j][1][1])%LJC;
            f[i][j][1][1]=(1ll*f[i][j][1][1]+f[i-1][j-1][0][1]+f[i-1][j-1][1][1])%LJC;
        }
    }
    f[n][0][0][0]=1;
    fu(j,1,n,1,1){
        f[n][j][0][0]=(1ll*f[n][j][0][0]+f[n-1][j-1][0][0]+f[n-1][j][0][0]+f[n-1][j][1][0])%LJC;
        f[n][j][1][0]=(1ll*f[n][j][1][0]+f[n-1][j-1][0][1]+f[n-1][j][0][1]+f[n-1][j][1][1])%LJC;
    }
    fu(i,0,n,1,1)h[i]=(1ll*fac[n-i]*(1ll*f[n][i][0][0]+f[n][i][1][0])%LJC)%LJC;
    int res=0;
    fu(i,m,n,1,1){
        res=(1ll*res+(1ll*(i-m&1?LJC-1:1)*C(i,m)%LJC*h[i]%LJC))%LJC;
    }
    printf("%d",res);
}