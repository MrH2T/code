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
const int MAXN = 100050,MAXM = 5000500;
int cnt,head[MAXN],to[MAXM],val[MAXM],nxt[MAXM];
void add(int u,int v,int w){nxt[++cnt]=head[u],head[u]=cnt,to[cnt]=v,val[cnt]=w;}
int n,m,c,st,ed;
priority_queue<pair<int,int> > q;
int vis[MAXN],dis[MAXN];
void dij(int s){
    memset(vis,0,sizeof(vis));memset(dis,0x3f,sizeof(dis));
    q.push(make_pair(0,s)),dis[s]=0;
    while(!q.empty()){
        int x=q.top().second;q.pop();
        if(vis[x])continue;vis[x]=1;
        for(int i=head[x],y=to[i];i;i=nxt[i],y=to[i]){
            if(!vis[y]&&dis[y]>dis[x]+val[i]){
                dis[y]=dis[x]+val[i];
                q.push(make_pair(-dis[y],y));
            }
        }
    }
}
signed main(){
    n=read(),m=read(),c=read();
    fu(i,1,m,1,1){
        int u=read(),v=read(),w=read();
        add(u,v,w);
    }
    fu(i,0,n,1,1){
        for(int k=1;k<=n;k<<=1){
            if((i^k)>n)continue; 
            add(i,i^k,k*c);
        }
    }
    st=read(),ed=read();
    dij(st);
    printf("%d",dis[ed]);
}
