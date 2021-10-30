#include<bits/stdc++.h>
// #define int long long
#define rint register int
#define fu(i,a,b,d,c) for(rint i=a;i<=b&&c;i+=d)
#define fd(i,a,b,d,c) for(rint i=a;i>=b&&c;i-=d)
using namespace std;
inline int read(){
    char c=0,f=1;int num=0;
    while(c<'0'||c>'9')((c=getchar())=='-')&&(f=-f);
    while(c>='0'&&c<='9')num=(num<<1)+(num<<3)+(c^48),c=getchar();
    return num*f;
}
typedef long long ll;
const int MAXN = 100050, MAXM = 300050, MAXK = 20, INF = 1e9;
int n,m;
template <class T>inline T Max(T x,T y){return x>y?x:y;}
template <class T>inline T Min(T x,T y){return x<y?x:y;}
template <class T>inline T Swap(T &x,T &y){T t=x;x=y,y=t;}

namespace Tree{
    struct Tri{
        int x,y,z;
        Tri(){};
        Tri(int u,int v,int w):x(u),y(v),z(w){}
    };
    struct Graph{
        int cnt,head[MAXN],to[MAXM<<1],nxt[MAXM<<1],val[MAXM<<1];
        void add(int u,int v,int w){
            nxt[++cnt]=head[u],head[u]=cnt,to[cnt]=v,val[cnt]=w;
        }
    }T;
    int dep[MAXN],fa[MAXN][MAXK+1],mx[MAXN][MAXK+1],smx[MAXN][MAXK+1];
    void dfs(int p,int fat){
        dep[p]=dep[fat]+1;
        fa[p][0]=fat,smx[p][0]=-INF;
        fu(i,1,MAXK,1,1){
            fa[p][i]=fa[fa[p][i-1]][i-1];
            int choosing[4]={mx[p][i-1],smx[p][i-1],
                mx[fa[p][i-1]][i-1],smx[fa[p][i-1]][i-1]};
            sort(choosing,choosing+4);
            mx[p][i]=choosing[3];
            int ptr=2;
            while(ptr>=0&&choosing[ptr]==choosing[3])ptr--;
            smx[p][i]=(~ptr)?choosing[ptr]:-INF;
        }
        for(int i=T.head[p],sn;i;i=T.nxt[i])if((sn=T.to[i])!=fat){
            mx[sn][0]=T.val[i];
            dfs(sn,p);
        }
    }
    int lca(int u,int v){
    	if(dep[u]<dep[v])Swap(u,v);
    	fd(i,MAXK,0,1,1)if(dep[fa[u][i]]>=dep[v])u=fa[u][i];
    	if(u==v)return u;
    	fd(i,MAXK,0,1,1)if(fa[u][i]!=fa[v][i])u=fa[u][i],v=fa[v][i];
    	return fa[u][0];
	}
	int queryChain(int u,int v,int va){
		int res=-INF;
    	if(dep[u]<dep[v])Swap(u,v);
    	fd(i,MAXK,0,1,1){
    		if(dep[fa[u][i]]>=dep[v]){
    			if(mx[u][i]==va)res=Max(res,smx[u][i]);
    			else res=Max(res,mx[u][i]);
    			u=fa[u][i];
			}
		}
		return res;
	}
    int query(int u,int v,int va){
    	int lc=lca(u,v);
    	return Max(queryChain(u,lc,va),queryChain(v,lc,va));
	}
}
namespace Kruskal{
    struct Edge{
        int u,v,w;
        Edge(){}
        Edge(int u_,int v_,int w_):u(u_),v(v_),w(w_){}
    };
    Edge e[MAXM];int egs=0;
    ll M0=0;
    bool inTree[MAXM];
    int fa[MAXN];
    int fnd(int x){
        return x==fa[x]?x:fa[x]=fnd(fa[x]);
    }
    void kruskal(){
        fu(i,1,n,1,1)fa[i]=i;
        sort(e+1,e+egs+1,[](Edge a,Edge b)->bool{return a.w<b.w;});
        int teg=0;
        fu(i,1,egs,1,1){
            int u=fnd(e[i].u),v=fnd(e[i].v);
            if(u!=v){
                fa[v]=u;
                Tree::T.add(e[i].u,e[i].v,e[i].w);
                Tree::T.add(e[i].v,e[i].u,e[i].w);
                M0+=e[i].w;
                inTree[i]=1,teg++;
            }
            if(teg==n-1)return Tree::dfs(1,0);
        }
    }
    ll subsmall(){
        ll ans=1LL*INF*INF;
        fu(i,1,egs,1,1)if(!inTree[i]){
            int u=e[i].u,v=e[i].v,w=e[i].w;
            int res=Tree::query(u,v,e[i].w);
            ans=Min(ans,M0+w-res);
        }
        return ans;
    }
}
signed main(){
    n=read(),m=read();
    fu(i,1,m,1,1){
        int u=read(),v=read(),w=read();if(u==v)continue;
        auto &eg=Kruskal::e[++Kruskal::egs];
        eg.u=u,eg.v=v,eg.w=w;;
    }
    Kruskal::kruskal();
    printf("%lld",Kruskal::subsmall());
}