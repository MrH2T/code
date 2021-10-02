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
const int MAXN = 2000050;
int prime[MAXN],mu[MAXN],mus[MAXN];
bool vis[MAXN];
void getMu(){
    vis[1]=mu[1]=1;
    fu(i,2,MAXN-50,1,1){
        if(!vis[i])prime[++prime[0]]=i,mu[i]=-1;
        for(int j=1;j<=prime[0]&&i*prime[j]<=MAXN-50;j++){
            mu[i*prime[j]]=i%prime[j]?-mu[i]:0;
            vis[i*prime[j]]=1;
            if(i%prime[j]==0)break;
        }
    }
    fu(i,1,MAXN-50,1,1)mus[i]=mus[i-1]+mu[i];
}
long long calc(int n,int d){
    n/=d;
    long long ans=0;
    for(int l=1,r;l<=n;l=r+1){
        r=n/(n/l);
        ans+=1LL*(mus[r]-mus[l-1])*(n/l)*(n/l);
    }
    return ans;
}
int n;
long long ans=0;
signed main(){
    n=read();getMu();
    fu(i,1,n,1,1){
        ans+=1LL*i*calc(n,i);
    }
    ans=ans-1LL*n*(n+1)/2;ans>>=1;
    printf("%lld",ans);
}