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
const int LJC = 1e9+7;
struct matr{
    int m[10][10];
    matr(){memset(m,0,sizeof(m));}
    void init(){fu(i,0,9,1,1)m[i][i]=1;}
    int* operator[](const int ind){return m[ind];}
    friend matr operator*(matr a,matr b){
        matr c;
        fu(i,0,9,1,1)fu(k,0,9,1,1)if(a[i][k])fu(j,0,9,1,1)c[i][j]=(1LL*c[i][j]+1LL*a[i][k]*b[k][j]%LJC)%LJC;
        return c;
    }
}trans,base;
matr qpow(matr a,long long p){
    matr res;res.init();
    for(;p;p>>=1,a=a*a)if(p&1)res=a*res;
    return res;
}
long long k;
signed main(){
    scanf("%lld",&k);
    fu(i,0,9,1,1){
        fu(j,max(0,i-2),min(9,i+2),1,1)trans[i][j]=1;
    }
    fu(i,0,9,1,1)base[i][0]=1;
    base=qpow(trans,k-1)*base;
    int res=0;
    fu(i,1-(k==1),9,1,1)res=(1LL*res+1LL*base[i][0])%LJC;
    printf("%d",res);
}