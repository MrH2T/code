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
const int MAXN = 4500;
int n,p;
int C[MAXN][MAXN];
int f[MAXN][2][2];// 0/1: peak/low
signed main(){
    n=read(),p=read();
    C[1][0]=C[1][1]=1;
    fu(i,2,n,1,1)C[i][0]=1;
    fu(i,2,n,1,1)fu(j,1,i,1,1)C[i][j]=(C[i-1][j]+C[i-1][j-1])%p;
    f[1][0][0]=f[1][0][1]=f[1][1][0]=f[1][1][1]=1;
    f[2][0][1]=1,f[2][1][0]=1;
    f[3][0][0]=2,f[3][1][1]=2;
    fu(i,4,n,1,1){
        (f[i][0][0]+=f[i-1][1][0]+f[i-1][0][1])%=p;
        (f[i][0][1]+=f[i-1][1][1])%=p;
        (f[i][1][0]+=f[i-1][1][1])%=p;
        (f[i][1][0]+=1ll*f[i-2][1][0]*C[i-1][1]%p)%=p;
        (f[i][1][1]+=1ll*f[i-2][1][1]*C[i-1][1]%p)%=p;
        (f[i][0][1]+=1ll*f[i-2][0][1]*C[i-1][1]%p)%=p;
        (f[i][1][1]+=1ll*f[i-2][1][1]*C[i-1][1]%p)%=p;
        fu(j,3,i-2,1,1){
            (f[i][0][0]+=1ll*f[j-1][0][1]*f[i-j][1][0]%p*C[i-1][j-1]%p)%=p;
            (f[i][0][1]+=1ll*f[j-1][0][1]*f[i-j][1][1]%p*C[i-1][j-1]%p)%=p;
            (f[i][1][0]+=1ll*f[j-1][1][1]*f[i-j][1][0]%p*C[i-1][j-1]%p)%=p;
            (f[i][1][1]+=1ll*f[j-1][1][1]*f[i-j][1][1]%p*C[i-1][j-1]%p)%=p;
        }
    }
    printf("%d\n",(1ll*f[n][0][0]+f[n][0][1]+f[n][1][0]+f[n][1][1])%p);
}