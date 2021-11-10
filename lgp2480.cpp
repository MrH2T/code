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
const int MAXN = 1e9+50, LJC = 999911659, LJC1= LJC-1;
const int P[5]={0,2,3,4679,35617},MAXP = 40050;
int fac[MAXP];
int b[5];
inline int qp(int x,int p, int md){
    int res=1;
    for(;p;p>>=1,x=1ll*x*x%md)(p&1)&&(res=1ll*res*x%md);
    return res;
}
inline int inv(int x,int p){
    return qp(x,p-2,p);
}
inline int C(int n,int m,int p){
    if(n<m)return 0;
    return 1ll*fac[n]*inv(fac[n-m],p)%p*inv(fac[m],p)%p;
}
inline int lucas(int n,int m,int p){
    if(n<m)return 0;if(!n)return 1;
    return 1ll*lucas(n/p,m/p,p)*C(n%p,m%p,p)%p;
} 
inline int crt(){
    int res=0;
    fu(i,1,4,1,1){
        res=(1ll*res+1ll*LJC1/P[i]*b[i]%LJC1*inv(LJC1/P[i],P[i]))%LJC1;
    }
    return res;
}
int n,g;
signed main(){
    n=read(),g=read();
    if(g==LJC)return printf("0")&0;
    fac[0]=1;
    int rtn=sqrt(n);
    fu(p,1,4,1,1){
        fu(i,1,P[p],1,1)fac[i]=1ll*fac[i-1]*i%P[p];
        fu(i,1,rtn,1,1){
            if(n%i==0){
                b[p]=(1ll*b[p]+lucas(n,i,P[p]))%P[p];
                if(i*i!=n){
                    b[p]=(1ll*b[p]+lucas(n,n/i,P[p]))%P[p];
                }
            }
        }
    }
    printf("%d",qp(g,crt(),LJC));
}