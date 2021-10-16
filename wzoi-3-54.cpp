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
const int MAXN = 100050, MAXV = 1000050;
int n,m,f[MAXV],a[MAXN],sz[MAXV];
int head[MAXV],nxt[MAXN],ed[MAXV];
int ans;
void merge(int x,int y){
    for(int i=head[x];i;i=nxt[i])ans-=(y==a[i-1])+(y==a[i+1]);
    for(int i=head[x];i;i=nxt[i])a[i]=y;
    nxt[ed[x]]=head[y],head[y]=head[x],sz[y]+=sz[x];
    ed[x]=sz[x]=head[x]=0;
}
signed main(){
    n=read(),m=read();
    fu(i,1,n,1,1){
        f[a[i]]=a[i]=read();
        if(!head[a[i]])ed[a[i]]=i;
        if(a[i]!=a[i-1])ans++;
        sz[a[i]]++,nxt[i]=head[a[i]],head[a[i]]=i;
    }
    fu(i,1,m,1,1){
        int op=read();
        if(op==2)printf("%d\n",ans);
        else {
            int x=read(),y=read();
            if(x==y)continue;
            if(sz[f[x]]>sz[f[y]])swap(f[x],f[y]);
            if(!sz[f[x]])continue;
            merge(f[x],f[y]);
        }
    }
}