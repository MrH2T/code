#include<bits/stdc++.h>
#define int long long
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
const int MAXN = 805;
int n,k,a[MAXN],b[MAXN];
int f[MAXN][MAXN],g[MAXN];
signed main(){
    n=read(),k=read();
    fu(i,1,n,1,1)a[i]=read(),b[i]=read();
    fu(i,1,n-1,1,1){
        if(a[i]+a[i+1]<=k)f[i][i+1]=b[i]+b[i+1];
        else f[i][i+1]=-1e17;
    }
    fu(len,4,n,2,1){
        fu(i,1,n-len+1,1,1){
            int j=i+len-1;
            f[i][j]=-1e17;
            if(a[i]+a[j]<=k)f[i][j]=f[i+1][j-1]+b[i]+b[j];
            fu(k,i+1,j-1,1,1){
                if((k-i+1)%2==0){
                    f[i][j]=max(f[i][j],f[i][k]+f[k+1][j]);
                }
            }
        }
    }
    fu(i,1,n,1,1){
        g[i]=g[i-1];
        fu(j,1,i-1,1,1)if(f[j][i]>=0)g[i]=max(g[i],g[j-1]+f[j][i]);
    }
    printf("%lld",g[n]);
}