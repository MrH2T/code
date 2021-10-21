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
const int MAXN = 105, MAXM = 2050, LJC = 998244353;
int n,m,a[MAXN][MAXM];
int f[MAXN][MAXM];
signed main(){
    n=read(),m=read();
    fu(i,1,n,1,1)fu(j,1,m,1,1)a[i][j]=read();
    
}