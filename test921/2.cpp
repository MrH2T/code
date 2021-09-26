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
#define toid(x,y) ((x-1)*m+y)
#define tox(id) (id/m+1)
#define toy(id) ((id-1)%m+1)
const int MAXN = 550;
struct edge{
	int u,v,val;
}e[MAXN*MAXN*2*2];
bool cmp(edge a,edge b){return a.val>b.val;}
int n,m,ecnt;
int fa[MAXN*MAXN];
int head[MAXN*MAXN],nxt[MAXN*MAXN<<1],to[MAXN*MAXN<<1],cnt;
void add(int u,int v){nxt[++cnt]=head[u];head[u]=cnt,to[cnt]=v;}
int getfa(int x){
	return fa[x]!=x?fa[x]=getfa(fa[x]):fa[x];
}

namespace LCA{
	const int MAXK = 20;
	int dep[MAXN*MAXN],fat[MAXN*MAXN][22];
	void dfs(int p,int f){
		fat[p][0]=f,dep[p]=dep[f]+1;
		fu(i,1,MAXK,1,1)fat[p][i]=fat[fat[p][i-1]][i-1];
		for(int i=head[p];i;i=nxt[i])if(to[i]!=f)dfs(to[i],p);
	}
	int lca(int u,int v){
		if(dep[u]<dep[v])swap(u,v);
		fd(i,MAXK,0,1,1){
			if(dep[fat[u][i]]>=dep[v])u=fat[u][i];
		}
		if(u==v)return v;
		fd(i,MAXK,0,1,1){
			if(fat[u][i]!=fat[v][i]){
				u=fat[u][i],v=fat[v][i];
			}
		}
		return fat[u][0];
	}
}
using namespace LCA;

signed main(){
    n=read(),m=read();
    fu(i,1,n,1,1){
    	fu(j,1,m,1,1){
    		int val1=read(),val2=read();
    		if(val1!=-1){
				e[++ecnt]=(edge){toid(i,j),toid(i+1,j),val1};
				e[++ecnt]=(edge){toid(i+1,j),toid(i,j),val1};
			}
			if(val2!=-1){
				e[++ecnt]=(edge){toid(i,j),toid(i,j+1),val2};
				e[++ecnt]=(edge){toid(i,j+1),toid(i,j),val2};
			}
		}
	}
	sort(e+1,e+ecnt+1,cmp);
	fu(i,1,n,1,1)fu(j,1,m,1,1)fa[toid(i,j)]=toid(i,j);
	fu(i,1,ecnt,1,1){
		int u=getfa(e[i].u),v=getfa(e[i].v);
		if(u!=v){
			fa[v]=u;
			add(e[i].u,e[i].v),add(e[i].v,e[i].u);
		}
	}
	dfs(1,0);
	
	int q=read();
	fu(i,1,q,1,1){
		int x=read(),y=read(),xx=read(),yy=read();
		int u=toid(x,y),v=toid(xx,yy);
		printf("%d\n",dep[u]+dep[v]-2*dep[lca(u,v)]);
	}
}
