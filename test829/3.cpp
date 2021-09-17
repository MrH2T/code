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
const int MAXN = 2050;
int n,k;
double p[MAXN],f[MAXN][MAXN],g[MAXN][MAXN];
double ans=0;
signed main(){
    n=read(),k=read();
    fu(i,1,n,1,1)scanf("%lf",p+i);
    sort(p+1,p+n+1);
    f[0][0]=1.0f;
    fu(i,1,n,1,1){
        fd(j,n,1,1,1)f[i][j]=f[i-1][j-1]*p[i]+f[i-1][j]*(1-p[i]);
        f[i][0]=(1-p[i])*f[i-1][0];
    }
    g[n+1][0]=1.0f;
    fd(i,n,1,1,1){
        fd(j,n,1,1,1)g[i][j]=g[i+1][j-1]*p[i]+g[i+1][j]*(1-p[i]);
        g[i][0]=(1-p[i])*g[i+1][0];
    }
    fu(i,0,k,1,1){
        double tmp=0.0f;
        fu(j,0,k/2,1,1)tmp+=f[i][j]*g[n-(k-i)+1][k/2-j];
        ans=max(ans,tmp);
    }
    printf("%lf",ans);
}