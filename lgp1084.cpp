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
const int MAXN = 50050;
typedef long long ll;
int n,m;
int cnt,head[MAXN],to[MAXN<<1],nxt[MAXN<<1];ll val[MAXN<<1];
void add(int u,int v,ll w){
    nxt[++cnt]=head[u],head[u]=cnt,to[cnt]=v,val[cnt]=w;
}
int pos[MAXN];
int fa[MAXN][21],dep[MAXN];
ll dis[MAXN][21];
void dfs(int p,int fat){
    fa[p][0]=fat,dep[p]=dep[fat]+1;
    fu(i,1,20,1,1)
        fa[p][i]=fa[fa[p][i-1]][i-1],dis[p][i]=dis[p][i-1]+dis[fa[p][i-1]][i-1];
    int cnt=0;
    for(int i=head[p],t;i;i=nxt[i])if((t=to[i])!=fat){
        if(p==1)cnt++;
        dis[t][0]=val[i];
        dfs(t,p);
    }
    if(p==1){if(m<cnt)exit(printf("-1")&0);}
}
pair<ll,int> ar[MAXN],nd[MAXN];
int uar,und;
bool vis[MAXN];
void dfs1(int p){
    int all=1,leaf=1;
    for(int i=head[p],t;i;i=nxt[i])if((t=to[i])!=fa[p][0]){
        dfs1(t);
        all&=vis[t],leaf=0;
    }
    if(p!=1&&all&&!leaf)vis[p]=1;
}
bool check(ll tm){
    uar=und=0;memset(vis,0,sizeof(vis));
    fu(i,1,m,1,1){      //this can be optimized by a prework
        int x=pos[i];ll ds=0;
        fd(i,20,0,1,1)if(fa[x][i]&&tm>=ds+dis[x][i])ds+=dis[x][i],x=fa[x][i];
        if(x!=1)vis[x]=1;
        else {
            int x1=pos[i];
            fd(i,20,0,1,1)if(fa[x1][i]>1)x1=fa[x1][i];
            ar[++uar]=make_pair(tm-ds,x1);
        }
    }
    dfs1(1);
    for(int i=head[1],t;i;i=nxt[i]){
        t=to[i];
        if(!vis[t])nd[++und]=make_pair(val[i],t);
    }
    sort(ar+1,ar+uar+1),sort(nd+1,nd+und+1);
    int j=1;
    fu(i,1,uar,1,1){
        if(!vis[ar[i].second])vis[ar[i].second]=1;
        else if(ar[i].first>=nd[j].first)vis[nd[j].second]=1;
        while(j<=und&&vis[nd[j].second])j++;
    }
    return j>und;
}
signed main(){
    ll l=0,r=0;
    n=read();
    fu(i,1,n-1,1,1){int u=read(),v=read();ll w=read();r+=w,add(u,v,w),add(v,u,w);}
    m=read();
    fu(i,1,m,1,1)pos[i]=read();
    dfs(1,0);   //meanwhile checked if there's solution
    ll ans=0;
    while(l<=r){
        ll mid=l+r>>1;
        if(check(mid))ans=mid,r=mid-1;
        else l=mid+1;
    }
    printf("%lld",ans);
}
