//Single Source Shortest Path & Multi-Source Shortest Path (no floyd)

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
const int MAXN = 100050, MAXM = 200050;
struct Graph{
    int cnt,head[MAXN],nxt[MAXM],to[MAXM],val[MAXM];
    Graph(){cnt=0,memset(head,0,sizeof(head)),memset(nxt,0,sizeof(nxt)),memset(to,0,sizeof(to)),memset(val,0,sizeof(val));}
    void add(int u,int v,int w){
        nxt[++cnt]=head[u],head[u]=cnt,to[cnt]=v,val[cnt]=w;
    }
};



// O(mlogn) , no negative edge
namespace Dijkstra{
    priority_queue<pair<int,int> >q;
    bool vis[MAXN];int dis[MAXN];
    int* solve(const Graph &g,int src){
        memset(dis,0x3f,sizeof(dis));
        memset(vis,0,sizeof(vis));
        while(!q.empty())q.pop();
        dis[src]=0;q.push(make_pair(0,src));
        while(!q.empty()){
            int x=q.top().second;q.pop();
            if(vis[x])continue;
            vis[x]=1;
            for(int i=g.head[x];i;i=g.nxt[i]){
                int t=g.to[i];
                if(dis[t]>dis[x]+g.val[i]){
                    dis[t]=dis[x]+g.val[i];
                    q.push(make_pair(-dis[t],t));
                }
            }
        }
        return dis;
    }
}


// O(km) ~ O(nm) , ok negative edge, check negative circle
namespace SPFA{
    queue<int> q;
    bool vis[MAXN];int dis[MAXN];
    int tm[MAXN];
    int* solve(const Graph &g,int src,int n){
        memset(dis,0x3f,sizeof(dis));
        memset(vis,0,sizeof(vis));
        memset(tm,0,sizeof(tm));
        while(!q.empty())q.pop();
        dis[src]=0,vis[src]=1;q.push(src);
        while(!q.empty()){
            int x=q.front();q.pop();vis[x]=0;

            if(++tm[x]>n){return NULL;}
            /*
            ! if a node has been visited for more than n-1 times,
                there's a negative circle in the graph.
            */

            for(int i=g.head[x];i;i=g.nxt[i]){
                int t=g.to[i];
                if(dis[t]>dis[x]+g.val[i]){
                    dis[t]=dis[x]+g.val[i];
                    if(!vis[t])q.push(t),vis[t]=1;
                }
            }
        }
        return dis;
    }
}


//All source shortest path
// O(nmlogn), first use SPFA to change the edge to positive then Dijkstra
namespace Johnson{
    Graph g1;
    void solve(Graph &g,int n){
        fu(i,1,n,1,1)g.add(n+1,i,0);
        int* res0=SPFA::solve(g,n+1,n);
        if(res0==NULL)exit(printf("-1")&0);
        fu(i,1,n,1,1){
            for(int j=g.head[i];j;j=g.nxt[j]){
                g1.add(i,g.to[j],g.val[j]+res0[i]-res0[g.to[j]]);
            }
        }
        fu(i,1,n,1,1){
            long long res=0;
            int *dis=Dijkstra::solve(g1,i);
            // fu(j,1,n,1,1)printf("%d ",dis[j]-res0[i]+res0[j]);putchar('\n');
            fu(j,1,n,1,1){
                if(dis[j]==0x3f3f3f3f)res+=1ll*j*1e9;
                else res+=1ll*j*(dis[j]-res0[i]+res0[j]);
            }
            printf("%lld\n",res);
        }
    }
}


Graph g;
int n,m,s;
signed main(){
    n=read(),m=read();
    fu(i,1,m,1,1){
        int u=read(),v=read(),w=read();
        g.add(u,v,w);
    }
    Johnson::solve(g,n);
}