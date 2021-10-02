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
const int MAXN = 50050;
int n,a,b,d;
int mu[MAXN],mus[MAXN],prime[MAXN],vis[MAXN];
void getMu(){
    vis[1]=mu[1]=1;
    fu(i,2,50000,1,1){
        if(!vis[i])prime[++prime[0]]=i,mu[i]=-1;
        for(int j=1;j<=prime[0]&&1LL*prime[j]*i<=50000;j++){
            mu[prime[j]*i]=i%prime[j]?-mu[i]:0;
            vis[prime[j]*i]=1;
            if(i%prime[j]==0)break;
        }
    }
    for(int i=1;i<=50000;i++)mus[i]=mus[i-1]+mu[i];
}
long long ans=0;
signed main(){
    n=read();
    getMu();
    while(n--){
        ans=0;
        a=read(),b=read(),d=read();
        a/=d,b/=d;
        int bound=min(a,b);
        for(int i=1;i<=bound;){
            int l=i,r=min(a/(a/i),b/(b/i));
            ans+=1LL*(mus[r]-mus[l-1])*(a/l)*(b/l);
            i=r+1;
        }
        printf("%lld\n",ans);
    }
}