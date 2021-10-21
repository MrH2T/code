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
typedef unsigned long long ull;
const int MAXN = 300050, P = 100, MAXK = 20, LJC = 13331;
inline void f_swap(int&u,int&v){int t=u;u=v,v=t;}
int n;
ull ppow[MAXN<<1];
namespace CFS{
    int cnt,head[MAXN],to[MAXN<<1],nxt[MAXN<<1];
    void add(int u,int v){
        nxt[++cnt]=head[u],head[u]=cnt,to[cnt]=v;
    }
}
char cc[MAXN];
int dep[MAXN],fa[MAXN][MAXK+1],sbabs[600050];
ull hadn[MAXN][MAXK+1],haup[MAXN][MAXK+1];
int haha[LJC];
void dfs(int p,int fat){
    dep[p]=dep[fat]+1;
    fa[p][0]=fat,haup[p][0]=hadn[p][0]=cc[p];
    fu(i,1,MAXK,1,1){
        fa[p][i]=fa[fa[p][i-1]][i-1];
        haup[p][i]=haup[p][i-1]+ppow[1<<i-1]*haup[fa[p][i-1]][i-1];
        hadn[p][i]=hadn[fa[p][i-1]][i-1]+ppow[1<<i-1]*hadn[p][i-1];
    }
    for(int i=CFS::head[p],sn;i;i=CFS::nxt[i])if((sn=CFS::to[i])!=fat){
        dfs(sn,p);
    }
}
int lca(int u,int v){
    if(dep[u]<dep[v])f_swap(u,v);
    fd(i,MAXK,0,1,1)if(dep[fa[u][i]]>=dep[v])u=fa[u][i];
    if(u==v)return v;
    fd(i,MAXK,0,1,1)if(fa[u][i]!=fa[v][i])u=fa[u][i],v=fa[v][i];
    return fa[u][0];
}
inline int kthfa(int u,int k){
	while(k){
		u=fa[u][haha[(k&-k)%LJC]];
		k-=k&-k;
	}
	return u;
}
inline int dis(int u,int v){return dep[u]+dep[v]-2*dep[lca(u,v)];}
ull chainHash(int u,int v,int k){
	if(k==0)return 0;
    k--;
    if(dep[u]>dep[v]){
        ull ha=0;int tmp=0,di=k;
        while(k){
        	ha+=ppow[tmp]*(haup[u][haha[(k&-k)%LJC]]);
        	tmp+=k&-k;
        	u=fa[u][haha[(k&-k)%LJC]];
        	k-=k&-k;
		}
        ha+=ppow[tmp]*cc[u];
        return ha;
    }
    else {
        ull ha=0;int tmp=0,di=k;
        v=kthfa(v,dep[v]-dep[u]-k);
        while(k){
        	tmp+=k&-k;
        	ha+=ppow[di+1-tmp]*hadn[v][haha[(k&-k)%LJC]];
        	v=fa[v][haha[(k&-k)%LJC]];
        	k-=k&-k;
		}
        ha+=cc[v];
        return ha;
    }
}
ull getHa(int u,int v,int k){
    int lc=lca(u,v);
    if(dep[u]-dep[lc]+1>=k)return chainHash(u,lc,k);
    else return chainHash(u,lc,dep[u]-dep[lc])+
		ppow[dep[u]-dep[lc]]*(chainHash(lc,v,k-(dep[u]-dep[lc])));
}
int query(int a,int b,int c,int d){
    if(dis(a,b)>dis(c,d))swap(a,c),swap(b,d);
    if(cc[a]!=cc[c])return 0;
    int l=1,r=dis(a,b)+1,res=0;
    while(l<=r){
    	int mid=l+r>>1;
    	if(getHa(a,b,mid)==getHa(c,d,mid))res=mid,l=mid+1;
    	else r=mid-1;
	}
	return res;
}

signed main(){
	fu(i,0,23,1,1)haha[(1<<i)%LJC]=i;
    ppow[0]=1;int zzzlalala=0;sbabs[0]=0;
    fu(i,1,600000,1,1){
        ppow[i]=ppow[i-1]*P;
        sbabs[i]=zzzlalala;
        if(!(i&i-1))zzzlalala++;
    }
    scanf("%d\n%s",&n,cc+1);
    fu(i,1,n-1,1,1){
        int u=read(),v=read();
        CFS::add(u,v),CFS::add(v,u);
    }
    dfs(1,0);
    int q=read();
    while(q--){
        int a=read(),b=read(),c=read(),d=read();
        printf("%d\n",query(a,b,c,d));
    }
}
