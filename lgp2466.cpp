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
const int MAXN = 1050;
struct tri{int u,v,w;}a[MAXN];
int n,c;
int f[MAXN][MAXN][2],sum[MAXN];
signed main(){
    int v0=0;
    n=read(),c=read();
    fu(i,1,n,1,1)a[i].u=read();
    fu(i,1,n,1,1)v0+=a[i].v=read();
    fu(i,1,n,1,1)a[i].w=read();

    a[++n]=(tri){c,0,0};
    sort(a+1,a+n+1,[](tri x,tri y)->bool{return x.u<y.u;});
    memset(f,0x3f,sizeof(f));
    fu(i,1,n,1,1)sum[i]=sum[i-1]+a[i].w,(a[i].u==c&&a[i].v==0)&&(f[i][i][0]=f[i][i][1]=0);
    fu(l,2,n,1,1){
        fu(i,1,n-l+1,1,1){
            int j=i+l-1;
            f[i][j][0]=min(f[i+1][j][0]+(sum[i]+sum[n]-sum[j])*(a[i+1].u-a[i].u),
                           f[i+1][j][1]+(sum[i]+sum[n]-sum[j])*(a[j].u-a[i].u));
            f[i][j][1]=min(f[i][j-1][0]+(sum[i-1]+sum[n]-sum[j-1])*(a[j].u-a[i].u),
                           f[i][j-1][1]+(sum[i-1]+sum[n]-sum[j-1])*(a[j].u-a[j-1].u));
        }
    }
    printf("%.3lf",double(v0-min(f[1][n][0],f[1][n][1]))/1000.0f);
}
