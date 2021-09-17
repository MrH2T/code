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
const int MAXN = 10050;
double f[MAXN],g[MAXN];
int n;
signed main(){
    n=read();
    fd(i,n-1,0,1,1){
        f[i]=f[i+1]+double(n)/double(n-i);
        g[i]=double(i)/double(n-i)*(f[i]+1)+g[i+1]+f[i+1]+1;
    }
    printf("%.2lf",g[0]);
}