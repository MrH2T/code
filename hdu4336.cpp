// vj465253i

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
const int MAXN = 25;
int n;
double p[MAXN];
signed main(){
    while(~scanf("%d",&n))
    {
        fu(i,1,n,1,1)scanf("%lf",&p[i]);
        double ans=0;
        fu(i,1,(1<<n)-1,1,1){
            double posi=0;
            int sb=0;
            fu(j,1,n,1,1)if(i&(1<<j-1))posi+=p[j],sb++;
            ans+=(sb&1?1:-1)/posi;
        }
        printf("%lf\n",ans);
    }
}
