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
const int MAXN = 200050;
int n,m;
int cnt,head[MAXN],nxt[MAXN<<1],to[MAXN<<1];
void add(int u,int v){nxt[++cnt]=head[u],head[u]=cnt,to[cnt]=v;}
int u[MAXN],v[MAXN],op[MAXN],x[MAXN];
bool bk[MAXN];
int ans[MAXN];
int fa[MAXN][21],dep[MAXN];
int bcnt,sz[MAXN],mxd[MAXN],d1[MAXN],d2[MAXN],root[MAXN];
int blk[MAXN];int mxdep,mxi;
void dfs(int p,int fat,int bl){
    blk[p]=bl,sz[bl]++;
    dep[p]=dep[fat]+1;fa[p][0]=fat;
    fu(i,1,20,1,1)fa[p][i]=fa[fa[p][i-1]][i-1];
    if(dep[p]>mxdep)mxi=p,mxdep=dep[p];
    for(int i=head[p],t;i;i=nxt[i])if((t=to[i])!=fat){
        dfs(t,p,bl);
    }
}
void getd(int p){
    mxdep=mxi=0,dfs(p,0,bcnt),d1[bcnt]=mxi;
    mxdep=mxi=0,dfs(d1[bcnt],0,bcnt),d2[bcnt]=mxi;
    mxd[bcnt]=dep[d2[bcnt]]-1;
    root[bcnt]=d1[bcnt];
}
inline int lca(int u,int v){
    if(dep[u]<dep[v])swap(u,v);
    fd(i,20,0,1,1)if(dep[fa[u][i]]>=dep[v])u=fa[u][i];
    if(u==v)return u;
    fd(i,20,0,1,1)if(fa[u][i]!=fa[v][i])u=fa[u][i],v=fa[v][i];
    return fa[u][0];
}
void merge(int u,int v){
    if(sz[blk[u]]<sz[blk[v]])swap(u,v);
    int b1=blk[u],b2=blk[v];
    dfs(v,u,b1);
    int d11=dep[d1[b1]]+dep[d1[b2]]-2*dep[lca(d1[b1],d1[b2])];
    int d12=dep[d1[b1]]+dep[d2[b2]]-2*dep[lca(d1[b1],d2[b2])];
    int d21=dep[d2[b1]]+dep[d1[b2]]-2*dep[lca(d2[b1],d1[b2])];
    int d22=dep[d2[b1]]+dep[d2[b2]]-2*dep[lca(d2[b1],d2[b2])];
    int dd1=mxd[b1],dd2=mxd[b2];
    int tmp[]={dd1,dd2,d11,d12,d21,d22};
    sort(tmp,tmp+6);
    if(tmp[5]==dd1)     d1[b1]=d1[b1],d2[b1]=d2[b1];
    else if(tmp[5]==dd2)d1[b1]=d1[b2],d2[b1]=d2[b2];
    else if(tmp[5]==d11)d1[b1]=d1[b1],d2[b1]=d1[b2];
    else if(tmp[5]==d12)d1[b1]=d1[b1],d2[b1]=d2[b2];
    else if(tmp[5]==d21)d1[b1]=d2[b1],d2[b1]=d1[b2];
    else                d1[b1]=d2[b1],d2[b1]=d2[b2];
    mxd[b1]=tmp[5];
    add(u,v),add(v,u);
}
signed main(){
	n=read(),m=read();
	fu(i,1,n-1,1,1){
		u[i]=read(),v[i]=read();
	}
	fu(i,1,m,1,1)op[i]=read(),x[i]=read(),(op[i]==1)&&(bk[x[i]]=1);
	fu(i,1,n-1,1,1)if(!bk[i])add(u[i],v[i]),add(v[i],u[i]);
    memset(bk,0,sizeof(bk));
    fu(i,1,n,1,1)if(!blk[i])bcnt++,getd(i);
	fd(i,m,1,1,1){
		if(op[i]==1){
            merge(u[x[i]],v[x[i]]);
		}
		else{
            int dd=d2[blk[x[i]]],ddd=d1[blk[x[i]]];
            int lc1=lca(dd,x[i]),lc2=lca(ddd,x[i]);
            ans[i]=max(dep[dd]+dep[x[i]]-2*dep[lc1],
                dep[ddd]+dep[x[i]]-2*dep[lc2]);
		}
	}
	fu(i,1,m,1,1)if(op[i]==2)printf("%d\n",ans[i]);
}