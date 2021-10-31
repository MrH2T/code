//vj465253d

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
const int MAXN = 450, LJC = 1e9+7;
int fac[MAXN],invfac[MAXN],inv[MAXN];
inline int C(int n,int m){
    if(n<m||m<0)return 0;
    return 1ll*fac[n]*invfac[m]%LJC*invfac[n-m]%LJC;
}
int n,m,c;
int ps[MAXN*MAXN];
signed main(){
    n=read(),m=read(),c=read();
    inv[1]=1;
    fu(i,2,400,1,1){
        inv[i]=1ll*(LJC-LJC/i)*inv[LJC%i]%LJC;
    }
    fac[0]=1,invfac[0]=1;
    fu(i,1,400,1,1)fac[i]=1ll*fac[i-1]*i%LJC,invfac[i]=1ll*invfac[i-1]*inv[i]%LJC;
    int ans=0;
    fu(k,0,c,1,1){
        ps[0]=1;
        fu(_,1,n*m,1,1)ps[_]=1ll*ps[_-1]*(c-k+1)%LJC;
        fu(i,0,n,1,1){
            fu(j,0,m,1,1){
                ans=(1ll*ans+(1ll*((i+j+k&1)?LJC-1:1)*C(n,i)%LJC*C(m,j)%LJC*C(c,k)%LJC
                    *ps[(n-i)*(m-j)]%LJC))%LJC;
            }
        }
    }
    printf("%d",ans);
}