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
const int MAXN = 100050, MOD = 1e9+7, MAXP = 2050;
int fac[MAXN<<1];
int inv(int x){
    for(int p=MOD-2,res=1;;((p&1)&&(res=res*x%MOD)),x=x*x%MOD,p>>=1)if(!p)return res;
}
int C(int n,int m){
    if(n<m)return 0ll;
    return fac[n]*inv(fac[m])%MOD*inv(fac[n-m])%MOD;
}
void init(){
    fac[0]=1;fu(i,1,200000,1,1)fac[i]=fac[i-1]*i%MOD;

}
int n,m,k,f[MAXP];
pair<int,int> a[MAXP];
signed main(){
    n=read(),m=read(),k=read();init();
    fu(i,1,k,1,1){int u=read(),v=read();a[i]=make_pair(u,v);}
    sort(a+1,a+k+1);
    a[++k]=make_pair(n,m);
    fu(i,1,k,1,1){
        f[i]=C(a[i].first+a[i].second-2,a[i].first-1);
        fu(j,1,i-1,1,1)if(a[j].second<=a[i].second){
            f[i]=f[i]-f[j]*C(a[i].first+a[i].second-a[j].first-a[j].second,a[i].first-a[j].first)%MOD;
            f[i]=(f[i]%MOD+MOD)%MOD;
        }
    }
    printf("%lld",f[k]);
}
