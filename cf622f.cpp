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
const int LJC = 1e9+7, MAXK = 1e6+50;
inline int qp(int x,int p){
    int res=1;
    for(;p;p>>=1,x=1ll*x*x%LJC)(p&1)&&(res=1ll*res*x%LJC);
    return res;
}
inline int inv(int x){return qp(x,LJC-2);}
int n,k,y[MAXK],fac[MAXK],pre[MAXK],suf[MAXK];
signed main(){
    n=read(),k=read();
    fac[0]=pre[0]=suf[k+3]=1;
    fu(i,1,k+2,1,1)y[i]=(1ll*y[i-1]+qp(i,k))%LJC;
    fu(i,1,k+2,1,1)fac[i]=1ll*fac[i-1]*i%LJC;
    fu(i,1,k+2,1,1)pre[i]=1ll*pre[i-1]*(LJC+n-i)%LJC;
    fd(i,k+2,1,1,1)suf[i]=1ll*suf[i+1]*(LJC+n-i)%LJC;
    int res=0;
    fu(i,1,k+2,1,1){
        res=(1ll*res+(1ll*y[i]*pre[i-1]%LJC*suf[i+1]%LJC*inv(1ll*fac[i-1]*fac[k+2-i]%LJC*(k+2-i&1?LJC-1:1)%LJC)%LJC))%LJC;
    }
    printf("%d",res);
}