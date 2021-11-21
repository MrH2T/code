#include<bits/stdc++.h>
#define int long long
#define rint register int
#define fu(i,a,b,d,c) for(rint i=a;i<=b&&c;i+=d)
#define fd(i,a,b,d,c) for(rint i=a;i>=b&&c;i-=d)
using namespace std;
inline int read(){
    char c=0,f=1;int num=0;
    while(c<'0'||c>'9')((c=getchar())=='-')&&(f=-f);
    while(c>='0'&&c<='9')num=(num<<1)+(num<<3)+(c^48),c=getchar();
    return num*f;
}
const int MAXN = 10050;
int n,a[MAXN];
int random(int l,int r){
    return (rand()%(r-l+1))+l;
}
int sqr(int x){return x*x;}
int sum=0,sum2=0;
int ans,tmp;
signed main(){
    freopen("variance.in","r",stdin);
    freopen("variance.out","w",stdout);
    n=read();fu(i,1,n,1,1)a[i]=read(),sum+=a[i],sum2+=sqr(a[i]);
    tmp=ans=n*sum2-sqr(sum);
    srand(time(0));
    fu(_,1,2000000,1,1){
        int pos=random(2,n-1);
        int M=sum-a[pos];
        int d1=a[pos-1]+a[pos+1]-2*a[pos];
        int d2=sqr(a[pos-1]+a[pos+1]-a[pos])-sqr(a[pos]);
        tmp+=n*(sum2+d2)-sqr(sum+d1)-n*(sum2)+sqr(sum);
        sum+=d1;
        sum2+=d2;
        a[pos]=a[pos-1]+a[pos+1]-a[pos];
        ans=min(ans,tmp);
    }
    printf("%lld\n",ans);
    return 0;
}
