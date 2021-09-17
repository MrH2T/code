#include<bits/stdc++.h>
using namespace std;
struct edge{int nxt,to;}e[100001<<1];
struct tree{
	int ans,l,r,tag,len;
	tree(){ans=l=r=tag=len=0;}
}tr[100001<<2];
int n,m,tot,h[100001],dep[100001],fa[100001],sz[100001];
int son[100001],id[100001],cnt,top[100001];
void add(int x,int y){
	e[++tot].nxt=h[x];
	h[x]=tot;
	e[tot].to=y;
}
int ls(int k){return k<<1;}
int rs(int k){return k<<1|1;}
tree merge(tree x,tree y){
	tree res;
	res.ans=x.ans+y.ans;
	res.len=x.len+y.len;
	if(x.r==y.l)++res.ans;
	res.l=x.l,res.r=y.r;
	return res;
}
void push_up(int k){tr[k]=merge(tr[ls(k)],tr[rs(k)]);}
void push_down(int k){
	if(tr[k].tag){
		tr[ls(k)].ans=tr[ls(k)].len-1;
		tr[rs(k)].ans=tr[rs(k)].len-1;
		tr[ls(k)].l=tr[ls(k)].r=tr[ls(k)].tag=tr[k].tag;
		tr[rs(k)].l=tr[rs(k)].r=tr[rs(k)].tag=tr[k].tag;		
		tr[k].tag=0;
	}
}
void build(int k,int l,int r){
	tr[k].len=r-l+1;tr[k].tag=tr[k].ans=0;
	if(l==r){tr[k].l=tr[k].r=l;return;}
	int mid=l+r>>1;
	build(ls(k),l,mid);build(rs(k),mid+1,r);
	push_up(k);
}
void update(int nl,int nr,int l,int r,int k,int p){
	if(nl<=l&&r<=nr){
		tr[k].ans=tr[k].len-1;
		tr[k].l=tr[k].r=tr[k].tag=p;
		return;
	}
	push_down(k);
	int mid=l+r>>1;
	if(nl<=mid)update(nl,nr,l,mid,ls(k),p);
	if(nr>mid)update(nl,nr,mid+1,r,rs(k),p);
	push_up(k);
}
tree query(int nl,int nr,int l,int r,int k){
	if(nl<=l&&r<=nr)return tr[k];
	push_down(k);
	int mid=l+r>>1;
	if(nr<=mid)return query(nl,nr,l,mid,ls(k));
	if(nl>mid)return query(nl,nr,mid+1,r,rs(k));
	return merge(query(nl,nr,l,mid,ls(k)),query(nl,nr,mid+1,r,rs(k)));
}
void dfs1(int k,int f,int deep){
	dep[k]=deep;fa[k]=f;sz[k]=1;son[k]=0;int mxson=-1;
	for(int i=h[k];i;i=e[i].nxt){
		if(e[i].to==f)continue;
		dfs1(e[i].to,k,deep+1);
		sz[k]+=sz[e[i].to];
		if(sz[e[i].to]>mxson){
			mxson=sz[e[i].to];
			son[k]=e[i].to;
		}
	}
}
void dfs2(int k,int tr){
	id[k]=++cnt;top[k]=tr;if(!son[k])return;
	dfs2(son[k],tr);
	for(int i=h[k];i;i=e[i].nxt){
		if(e[i].to==fa[k]||e[i].to==son[k])continue;
		dfs2(e[i].to,e[i].to);
	}
}
void modify(int x,int y,int p){
	while(top[x]^top[y]){
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		update(id[top[x]],id[x],1,n,1,p);
		x=fa[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	update(id[x],id[y],1,n,1,p);
}
int LCA(int x,int y){
	while(top[x]^top[y]){
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		x=fa[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	return x;
}
int getChain(int x,int lca){
	tree res;
	while(top[x]^top[lca]){
		res=merge(query(id[top[x]],id[x],1,n,1),res);
		x=fa[top[x]];
	}
	res=merge(query(id[lca],id[x],1,n,1),res);
	return res.ans;
}
int solve(int x,int y){
	int lca=LCA(x,y);
	return getChain(x,lca)+getChain(y,lca);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;++i){
		int x,y;scanf("%d%d",&x,&y);
		add(x,y);add(y,x);
	}
	dfs1(1,0,1);dfs2(1,1);build(1,1,n);
	for(int i=1;i<=m;++i){
		int opt,x,y;scanf("%d%d%d",&opt,&x,&y);
		if(opt==1)modify(x,y,i+n);
		if(opt==2)printf("%d\n",solve(x,y));
	}
}
