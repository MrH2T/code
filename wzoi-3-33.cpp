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
const int MAXN = 500050;
int n;
int cnt,head[MAXN],nxt[MAXN<<1],to[MAXN<<1];
double val[MAXN<<1],q[MAXN];
void add(int u,int v,double w){
    nxt[++cnt]=head[u],head[u]=cnt,to[cnt]=v,val[cnt]=w;
}
double f[MAXN],ans;
void dfs(int p,int fa){
    f[p]=q[p];
    for(int i=head[p],son;i;i=nxt[i])if((son=to[i])!=fa){
        dfs(son,p);
        f[p]=f[p]+f[son]*val[i]-f[p]*f[son]*val[i];
    }
}
void dfs1(int p,int fa){
    ans+=f[p];
    for(int i=head[p],son;i;i=nxt[i])if((son=to[i])!=fa){
        if(f[son]!=1.0f){
            double k=(f[p]-f[son]*val[i])/(1-f[son]*val[i]);
            f[son]=f[son]+k*val[i]-f[son]*k*val[i];
        }
        dfs1(son,p);
    }
}
signed main(){
    n=read();
    fu(i,1,n-1,1,1){
        int u=read(),v=read();
        double w=(double)read()/100.0f;
        add(u,v,w),add(v,u,w);
    }
    fu(i,1,n,1,1)q[i]=(double)read()/100.0f;
    dfs(1,0);
    dfs1(1,0);
    printf("%.6lf",ans);
}