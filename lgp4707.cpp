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
const int MAXN = 1050, MAXM=10050,LJC = 998244353;
int qp(int x,int p){int res=1;for(;p;p>>=1,x=1ll*x*x%LJC)(p&1)&&(res=1ll*res*x%LJC);return res;}
int inv[MAXM];
int n,m,k,invm,f[15][MAXM],sbabs,p;
signed main(){
    n=read(),k=read(),m=read();
    k=n+1-k,inv[1]=1;
    fu(i,2,m,1,1)inv[i]=1ll*(LJC-LJC/i)*inv[LJC%i]%LJC;
    fu(i,1,k,1,1)f[i][0]=-1;
    fu(i,1,n,1,1){
        sbabs+=p=read();
        fd(j,sbabs,p,1,1){
            fd(l,k,1,1,1)
                f[l][j]=(1ll*f[l][j]+f[l-1][j-p]-f[l][j-p]+LJC)%LJC;
        }
    }
    int ans=0;
    fu(i,1,m,1,1){
        ans=(1ll*ans+1ll*f[k][i]*inv[i]%LJC)%LJC;
    }
    printf("%d",1ll*ans*m%LJC);
}