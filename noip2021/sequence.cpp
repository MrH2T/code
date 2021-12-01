#include<bits/stdc++.h>
#define rint register int
#define fu(i,a,b,d,c) for(rint i=a;i<=b&&c;i+=d)
#define fd(i,a,b,d,c) for(rint i=a;i>=b&&c;i-=d)
using namespace std;
inline int read(){
    char c=0,f=1;int num=0;
    while(c<'0'||c>'9')((c=getchar())=='-')&&(f=-f);
    while(c>='0'&&c<='9')num=(num<<1)+(num<<3)+(c^48),c=getchar();
    return num*f;
}
const int MAXM = 120, MAXN = 35,LJC = 998244353;
int v[MAXM],n,m,k;
int f[MAXM][MAXN][MAXN][MAXN];
int inv[MAXM],fac[MAXM],invfac[MAXM];
inline int C(int n,int m){
    if(n<m||m<0)return 0;
    return 1ll*fac[n]*invfac[n-m]%LJC*invfac[m]%LJC;
}
inline int qp(int x,int p){
    int res=1;
    for(;p;p>>=1,x=1ll*x*x%LJC)(p&1)&&(res=1ll*res*x%LJC);
    return res;
}
signed main(){
    freopen("sequence.in","r",stdin);
    freopen("sequence.out","w",stdout);

    n=read(),m=read(),k=read();
    fu(i,0,m,1,1)v[i]=read();

    inv[1]=fac[0]=invfac[0]=1;
    fu(i,2,n,1,1)inv[i]=1ll*(LJC-LJC/i)*inv[LJC%i]%LJC;
    fu(i,1,n,1,1)fac[i]=1ll*fac[i-1]*i%LJC,invfac[i]=1ll*invfac[i-1]*inv[i]%LJC;

    fu(i,1,m+7,1,1){
        if(i-1<=m)f[i][1][1][1]=v[i-1];
        fu(j,2,n,1,1){
            fu(k,1,i,1,1){
                fu(l,1,n,1,1){
                    fu(t,0,n-j,1,1){
                        (f[i][j+t][k+(l+t)%2][(l+t)/2]+=f[i-1][j][k][l]*qp(v[i-1],t)%LJC*C(n-j,t)%LJC)%=LJC;
                    }
                }
            }
        }
    }
    int ans=0;
    fu(i,1,k,1,1){
        ans=(1ll*ans+f[m+7][n][i][0])%LJC;
    }
    printf("%d\n",ans);
    return 0;
}