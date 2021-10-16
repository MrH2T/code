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
const int MAXN = 100050;
int n,cnt;
int head[MAXN], nxt[MAXN<<1], to[MAXN<<1];
void add(int u,int v){nxt[++cnt]=head[u],head[u]=cnt,to[cnt]=v;}
int dep[MAXN];
long double ans;
void dfs(int p,int fa){
    dep[p]=dep[fa]+1;
    ans+=1.0f/(double)dep[p];
    for(int i=head[p];i;i=nxt[i]){
        if(to[i]!=fa)dfs(to[i],p);
    }
}
signed main(){
    n=read();
    fu(i,1,n-1,1,1){
        int u=read(),v=read();
        add(u,v),add(v,u);
    }
    dfs(1,0);
    printf("%Lf",ans);
}