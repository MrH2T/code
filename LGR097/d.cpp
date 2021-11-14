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
const int LJC = 998244353, MAXN = 2050;
inline int inv(int x){
    int res=1,p=LJC-2;
    for(;p;p>>=1,x=1ll*x*x%LJC)(p&1)&&(res=1ll*res*x%LJC);
    return res;
}
int T,n,s;
int solve(int n,int s){
    int res1=1ll*n*(n-1)%LJC*inv(2)%LJC;
    int res2=1,res3=1;
    fd(i,s+1,s-n+1,1,1)res2=1ll*res2*i%LJC;
    fd(i,n+1,1,1,1)res3=1ll*res3*i%LJC;
    return 1ll*res1*res2%LJC*inv(res3)%LJC;
}
signed main(){
    T=read();
    while(T--){
        n=read(),s=read();
        printf("%d\n",solve(n,s));
    }
}