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
const int MAXN = 20050;
int prime[MAXN],vis[MAXN],cnt;
int win[MAXN],f[MAXN];
signed main(){
    fu(i,2,20000,1,1){
        if(!vis[i])prime[++cnt]=i;
        for(int j=1;j<=cnt&&i*prime[j]<=20000;j++){
            vis[i*prime[j]]=1;
            if(i%prime[j]==0)break;
        }
    }
    win[0]=0;
    fu(i,1,20000,1,1){
        for(int j=1;j<=cnt&&prime[j]<=i;j++)if(!win[i-prime[j]]){win[i]=1;break;}
    }
    fu(i,0,20000,1,1){
        if(win[i])f[i]=1e9;
        for(int j=1;j<=cnt&&prime[j]<=i;j++){
            if(win[i]&&!win[i-prime[j]]){
                f[i]=min(f[i],f[i-prime[j]]+1);
            }else if(!win[i]&&win[i-prime[j]]){
                f[i]=max(f[i],f[i-prime[j]]+1);
            }
        }
    }
    int T=read();
    while(T--){
        int n=read();
        printf("%d\n",(!win[n])?-1:f[n]);
    }

}
