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
const int MAXN = 205;
int n,w[MAXN];
int f[MAXN][MAXN];
signed main(){
    n=read();fu(i,1,n,1,1)w[i+n]=w[i]=read();
    w[2*n+1]=w[1];
    fu(l,2,n,1,1){
        fu(i,1,2*n-l+1,1,1){
            int j=i+l-1;
            fu(k,i,j-1,1,1)
                f[i][j]=max(f[i][j],f[i][k]+f[k+1][j]+w[i]*w[k+1]*w[j+1]);
        }
    }
    int ans=0;
    fu(i,1,n,1,1)ans=max(ans,f[i][i+n-1]);
    printf("%d",ans);
}