//sigma(i^k*Fib(i))
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

const int LJC = 1e9+7, MAXK = 50;
int qp(int x,int p){
    int res=1;
    for(x%=LJC;p;x=1ll*x*x%LJC,p>>=1)(p&1)&&(res=1ll*res*x%LJC);
    return res;
}
int inv(int x){return qp(x,LJC-2);}
struct S{
    int a,b;
    S():a(0),b(0){}
    S(int a_,int b_):a(a_%LJC),b(b_%LJC){}
    S operator+(const S y){return S((a+y.a)%LJC,(b+y.b)%LJC);}
    S operator-(const S y){return S((a-y.a+LJC)%LJC,(b-y.b+LJC)%LJC);}
    S operator*(const S y){return S(1ll*(1ll*a*y.a%LJC+5ll*b*y.b%LJC)%LJC,1ll*(1ll*a*y.b%LJC+1ll*b*y.a%LJC)%LJC);}
    S operator/(const S y){
        int fm=inv(((1ll*y.a*y.a%LJC-5ll*y.b*y.b%LJC)%LJC+LJC)%LJC);
        return S(1ll*((1ll*a*y.a%LJC-5ll*b*y.b%LJC)%LJC+LJC)%LJC*fm%LJC,1ll*((1ll*b*y.a%LJC-1ll*a*y.b%LJC)%LJC+LJC)%LJC*fm%LJC);
    }
};
S qp(S x,int p){
    S res(1,0);
    for(;p;x=x*x,p>>=1)(p&1)&&(res=res*x,0);
    return res;
}
void write(int n){
    if(n==0)putchar('0');
    char c[30]={0};int len=0;
    while(n)c[++len]=n%10+'0',n/=10;
    while(len)putchar(c[len--]);
}
int n;
int k;
S ansA[MAXK],ansB[MAXK];
int C[MAXK][MAXK];
signed main(){
    n=read(),k=read();
    S A(inv(2),inv(2)),B(inv(2),LJC-inv(2));
    C[0][0]=1;
    fu(i,1,k,1,1){
        C[i][0]=1;
        fu(j,1,i,1,1)C[i][j]=(1ll*C[i-1][j-1]+C[i-1][j])%LJC;
    }
    ansA[0]=A*((qp(A,n)-S(1,0))/(A-S(1,0)));
    ansB[0]=B*((qp(B,n)-S(1,0))/(B-S(1,0)));
    fu(i,1,k,1,1){
        S tmpA(0,0),tmpB(0,0);
        fu(j,0,i-1,1,1){
            tmpA=tmpA+S(((i-j&1)?LJC-1:1),0)*S(C[i][j],0)*(ansA[j]-A);
            tmpB=tmpB+S(((i-j&1)?LJC-1:1),0)*S(C[i][j],0)*(ansB[j]-B);
        }
        tmpA=tmpA-A+S(qp(n,i),0)*qp(A,n+1);
        tmpB=tmpB-B+S(qp(n,i),0)*qp(B,n+1);
        ansA[i]=tmpA/(A-S(1,0));
        ansB[i]=tmpB/(B-S(1,0));
    }
    S res=((A*ansA[k]-B*ansB[k])/S(0,1));
    // printf("%lld",res.a);
    write(res.a);
}