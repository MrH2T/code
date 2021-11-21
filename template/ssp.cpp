//Sub Shortest Path

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
//when loosing, save the second-shortest and the shortest path
//many 'if's
namespace SPFA{
    int dis1[MAXN],dis2[MAXN];
    bool vis[MAXN];
    queue<int> q;
    pair<int*,int*> solve(const Graph &g,int src){
        memset(dis1,0x3f,sizeof(dis1));
        memset(dis2,0x3f,sizeof(dis2));
        while(!q.empty())q.pop();
        vis[src]=1,dis1[src]=0;
        q.push(src);
        while(!q.empty()){
            int x=q.front();q.pop();
            vis[x]=0;
            for(int i=g.head[x];i;i=g.nxt[i]){
                int t=g.to[i];
                if(dis1[t]>dis1[x]+g.val[i]){
                    dis2[t]=dis1[t];
                    dis1[t]=dis1[x]+g.val[i];
                    if(!vis[t])vis[t]=1,q.push(t);
                }
                if(dis2[t]>dis2[x]+g.val[i]){
                    dis2[t]=dis2[x]+g.val[i];
                    if(!vis[t])vis[t]=1,q.push(t);
                }
                if(dis1[t]<dis1[x]+g.val[i]&&dis2[t]>dis1[x]+g.val[i]){
                    dis2[t]=dis1[x]+g.val[i];
                    if(!vis[t])vis[t]=1,q.push(t);
                }
            }
        }
        return make_pair(dis1,dis2);
    }
}
Graph g;
int n,m,s;
signed main(){
    n=read(),m=read(),s=read();
    fu(i,1,m,1,1){
        int u=read(),v=read(),w=read();
        g.add(u,v,w),g.add(v,u,w);
    }
    pair<int*,int*> res=SPFA::solve(g,s);
    fu(i,1,n,1,1)printf("%d ",res.second[i]);
}