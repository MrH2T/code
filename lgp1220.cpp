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
const int MAXN = 55;
int n,c,pos[MAXN],w[MAXN];
int f[MAXN][MAXN][2],sum[MAXN][MAXN];
signed main(){
    n=read(),c=read();
    fu(i,1,n,1,1)pos[i]=read(),w[i]=read();
    fu(i,1,n,1,1)fu(j,i,n,1,1)fu(k,i,j,1,1)sum[i][j]+=w[k];
    int s=sum[1][n];
    fu(i,1,n,1,1)fu(j,i,n,1,1)sum[i][j]=s-sum[i][j];
    memset(f,0x3f,sizeof(f));
    f[c][c][0]=f[c][c][1]=0;
    fu(k,2,n,1,1){
        fu(i,1,n-k+1,1,1){
            int j=i+k-1;
            f[i][j][0]=min(f[i+1][j][0]+sum[i+1][j]*(pos[i+1]-pos[i]),
                           f[i+1][j][1]+sum[i+1][j]*(pos[j]-pos[i]));
            f[i][j][1]=min(f[i][j-1][0]+sum[i][j-1]*(pos[j]-pos[i]),
                           f[i][j-1][1]+sum[i][j-1]*(pos[j]-pos[j-1]));
        }
    }
    printf("%d",min(f[1][n][0],f[1][n][1]));
}