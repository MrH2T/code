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
const int MAXK = 105, MAXN = 16;
int k,n;
int base[MAXN],p[MAXN];
double f[MAXK][1<<MAXN];
signed main(){
    k=read(),n=read();
    fu(i,1,n,1,1){
        p[i]=read();
        int x=read();
        while(x)base[i]|=(1<<x-1),x=read();
    }
    fd(i,k,1,1,1){
        fu(s,0,(1<<n)-1,1,1){
            fu(j,1,n,1,1){
                if((base[j]&s)==base[j])f[i][s]+=max(f[i+1][s],f[i+1][s|(1<<j-1)]+p[j]);
                else f[i][s]+=f[i+1][s];
            }
            f[i][s]/=n;
        }
    }
    printf("%.6lf",f[1][0]);
}
