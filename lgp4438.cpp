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
const int MAXN = 40050;
typedef unsigned long long ull;
int n,ls[MAXN],rs[MAXN];
int a[MAXN],b[MAXN],c[MAXN];
int id(int x){
    return x>0?x:-x+n-1;
}
ull f[42][42][42][2];
inline bool leaf(int u){return !(ls[u]&&rs[u]);}
void dfs(int p,int dep,int idx){
    if(!p)return;
    if(leaf(p)){
        fu(x,0,40,1,1)fu(y,0,40,1,1)f[dep][x][y][idx]=1ull*c[p]*(a[p]+x)*(b[p]+y);
        return;
    }
    dfs(ls[p],dep+1,0);
    dfs(rs[p],dep+1,1);
    fu(x,0,40,1,1)fu(y,0,40,1,1){
        f[dep][x][y][idx]=min(
            f[dep+1][x+1][y][0]+f[dep+1][x][y][1],
            f[dep+1][x][y][0]+f[dep+1][x][y+1][1]
        );
    }
}
signed main(){
    n=read();
    fu(i,1,n-1,1,1)ls[i]=id(read()),rs[i]=id(read());
    fu(i,1,n,1,1)a[id(-i)]=read(),b[id(-i)]=read(),c[id(-i)]=read();
    dfs(1,1,0);
    printf("%lld",f[1][0][0][0]);
}