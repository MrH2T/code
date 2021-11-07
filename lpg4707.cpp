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
const int MAXN = 1050, LJC = 998244353;
int qp(int x,int p){int res=1;for(;p;p>>=1,x=1ll*x*x%LJC)(p&1)&&(res=1ll*res*x%LJC);return res;}
int inv[MAXN],fac[MAXN],invfac[MAXN];
int n,m,k,invm;
int p[MAXN];
signed main(){
    n=read(),k=read(),m=read();
    inv[1]=fac[0]=invfac[0]=1;
    fu(i,2,n,1,1)inv[i]=1ll*(LJC-LJC/i)*inv[LJC%i]%LJC;
    fu(i,1,n,1,1)fac[i]=1ll*fac[i-1]*i%LJC,invfac[i]=1ll*invfac[i-1]*inv[i]%LJC;
    invm=qp(m,LJC-2);
    fu(i,1,n,1,1)p[i]=read();
    
}