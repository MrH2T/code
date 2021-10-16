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
const int MAXN = 2050, MAXV= 350;
int n,m,v,e;
int c[MAXN],d[MAXN];
int dis[MAXV][MAXV];
double k[MAXN],f[MAXN][MAXN][2];
signed main(){
    memset(dis,0x3f,sizeof(dis));
    n=read(),m=read(),v=read(),e=read();
    fu(i,1,n,1,1)c[i]=read();
    fu(i,1,n,1,1)d[i]=read();
    fu(i,1,n,1,1)scanf("%lf",&k[i]);
    fu(i,1,e,1,1){
        int u=read(),v=read(),w=read();
        dis[u][v]=dis[v][u]=min(dis[u][v],w);
    }
    fu(t,1,v,1,1)fu(i,1,v,1,1)fu(j,1,v,1,1)dis[i][j]=min(dis[i][j],dis[i][t]+dis[t][j]);
    fu(i,1,v,1,1)dis[i][i]=0;       //important!
    fu(i,0,n,1,1)fu(j,0,m,1,1)f[i][j][0]=f[i][j][1]=1e9;
    f[1][0][0]=f[1][1][1]=0;
    fu(i,2,n,1,1){
        f[i][0][0]=f[i-1][0][0]+dis[c[i-1]][c[i]];
        fu(j,1,min(i,m),1,1){
            f[i][j][0]=min(f[i-1][j][0]+dis[c[i-1]][c[i]],f[i-1][j][1]+dis[d[i-1]][c[i]]*k[i-1]
                +dis[c[i-1]][c[i]]*(1-k[i-1]));
            f[i][j][1]=min(f[i-1][j-1][0]+dis[c[i-1]][d[i]]*k[i]+dis[c[i-1]][c[i]]*(1-k[i]),
                f[i-1][j-1][1]+dis[c[i-1]][c[i]]*(1-k[i-1])*(1-k[i])+dis[c[i-1]][d[i]]*
                (1-k[i-1])*k[i]+dis[d[i-1]][c[i]]*k[i-1]*(1-k[i])+dis[d[i-1]][d[i]]*k[i-1]*k[i]);
        
        }
    }
    double ans=1e9;
    fu(i,0,m,1,1)ans=min(ans,min(f[n][i][0],f[n][i][1]));
    printf("%.2lf",ans);
}