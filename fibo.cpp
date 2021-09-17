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
const int MAXN = 1050;
int fib[MAXN],cnt=1;
int n,m,p;
int ha[MAXN],sg[MAXN];
signed main(){
    fib[0]=fib[1]=1;
    while(fib[cnt]<=1000)cnt++,fib[cnt]=fib[cnt-1]+fib[cnt-2];
    sg[0]=0;
    fu(i,1,1000,1,1){
        memset(ha,0,sizeof(ha));
        for(int j=1;fib[j]<=i&&j<=cnt;j++)ha[sg[i-fib[j]]]=1;
        fu(j,0,1000,1,1)if(!ha[j]){sg[i]=j;break;}
    }
    while(1){
        n=read(),m=read(),p=read();
        if(n==0&&m==0&&p==0)return 0;
        if((sg[n]^sg[m]^sg[p])==0)puts("Nacci");
        else puts("Fibo");
    }
}