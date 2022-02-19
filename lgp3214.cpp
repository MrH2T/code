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
const int MAXN = 1000050, LJC = 1e8+7;
inline int qp(int x,int p){
    int res=1;
    for(;p;p>>=1,x=1ll*x*x%LJC)(p&1)&&(res=1ll*res*x%LJC);
    return res;
}
inline int inv(int x){return qp(x,LJC-2);}
int f[MAXN],n,m;
int a[MAXN];//(2^n-1,i) * (i)!
signed main(){
    n=read(),m=read();
    a[0]=1;
    int full=qp(2,n);
    fu(i,1,m,1,1)a[i]=1ll*a[i-1]*((full-i)%LJC+LJC)%LJC;
    f[0]=1,f[1]=0;
    fu(i,2,m,1,1){
        f[i]=(((a[i-1]-f[i-1])%LJC-(1ll*f[i-2]*(full-i+1)%LJC*(i-1)%LJC))%LJC+LJC)%LJC;
    }
    int m1=1;fu(i,1,m,1,1)m1=1ll*m1*i%LJC;
    printf("%d",1ll*f[m]*inv(m1)%LJC);
}
