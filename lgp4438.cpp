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
vector<ull> f[MAXN][41];
void dfs(int p,int dep){
    fu(i,0,dep,1,1)f[p][i].resize(dep+1);
    
}
signed main(){
    n=read();
    fu(i,1,n-1,1,1)ls[i]=id(read()),rs[i]=id(read());
    fu(i,1,n,1,1)a[id(-i)]=read(),b[id(-i)]=read(),c[id(-i)]=read();
    dfs(1,0);
}