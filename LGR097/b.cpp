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
typedef long long ll;
const int MAXN= 100050;
int T,n,q;
double a[MAXN];
ll sum[MAXN];
signed main(){
    T=read();
    while(T--){
        n=read(),q=read();
        fu(i,1,n,1,1)a[i]=read();
        sort(a+1,a+n+1);
        fu(i,1,n,1,1)sum[i]=sum[i-1]+a[i];
        fu(_,1,q,1,1){
            int k=read();
            int l=1;
            while(1){
                double aver=
                   double(sum[n]-sum[l-1])/double(n-l+1)-k;
                int pos=lower_bound(a+1,a+n+1,aver)-a-1;
                if(pos<l)break;
                l=pos+1;
            }
            printf("%d ",n-l+1);
        }
        putchar('\n');
    }
}