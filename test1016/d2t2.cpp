#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define rint register int
#define fu(i,a,b,d,c) for(rint i=a;i<=b&&c;i+=d)
#define fd(i,a,b,d,c) for(rint i=a;i>=b&&c;i-=d)
using namespace std;
inline int read(){
	char c=0,f=1;int num=0;
	while((c<'0'||c>'9')&&c!='-')((c=getchar())=='-')&&(f=-f);
	while(c>='0'&&c<='9')num=(num<<1)+(num<<3)+(c^48),c=getchar();
	return num*f;
}
typedef long long ll;
const int MOD = 19260817, MAXN = 100050;
inline ll qpow(int x,int p){
	int res=1;
	for(;p;p>>=1,x=1LL*x*x%MOD)(p&1)&&(res=1LL*res*x%MOD);
	return res;
}
inline ll inv(int x){
	return qpow(x,MOD-2);
}
struct oper{
	int tp;
	int x,y,t;
}stk[MAXN];
int ops=0;
unordered_map<int,int> val[MAXN];
multiset<ll> eg;
ll shxhs(int u,int v){return 1ll*u+1000000ll*v;}
inline int gU(ll e){return e%1000000;}
inline int gV(ll e){return e/1000000;}
int n,m,q,rtn;
int cnt,head[MAXN],to[MAXN<<1],nxt[MAXN<<1];
int ccnt,hd[MAXN],tt[MAXN<<1],nnxt[MAXN<<1];
int bel[MAXN],sz[MAXN];
int uuu[MAXN],vvv[MAXN];
inline int fid(int x){
	return x!=bel[x]?bel[x]=fid(bel[x]):x;
}
inline void add(int u,int v){
	nxt[++cnt]=head[u],to[cnt]=v,head[u]=cnt;
}
inline void add1(int u,int v){
	nnxt[++ccnt]=hd[u],hd[u]=ccnt,tt[ccnt]=v;
}
void dfs(int p,int fa){
	bel[p]=bel[fa];
	for(int i=head[p];i;i=nxt[i])if(bel[to[i]]==to[i]&&to[i]!=fa){
		dfs(to[i],p);
		int v=to[i];
		int szv=val[v].size();
		if(szv<=rtn){//brute force merge
			for(int j=hd[v];j;j=nnxt[j])add1(p,tt[j]);
			for(pair<int,int> j:val[v])val[p][(j).first]+=(j).second;
		}
		else add1(p,v);
		sz[p]+=sz[v];
	}
	
}
int dfs1(int p,int fa,int y){
	int res=0;
	for(int i=hd[p];i;i=nnxt[i])res+=dfs1(tt[i],p,y);
	return res+val[p][y];
}
ll fac[1000050];
int ans[MAXN],anstop;
signed main(){
//	freopen("mc1.in","r",stdin);
//	freopen("2-me.out","w",stdout);
	n=read(),m=read(),q=read();
	rtn=sqrt(n);
	fac[0]=1;
	fu(i,1,1000000,1,1)fac[i]=fac[i-1]*i%MOD;
	fu(i,1,n,1,1){
		int c=read(),y=read();
		sz[i]=val[i][y]=c;
		bel[i]=i;
	}
	fu(i,1,m,1,1){
		int u=read(),v=read();
		uuu[i]=u,vvv[i]=v;
		eg.insert(shxhs(u,v)),eg.insert(shxhs(v,u));
	}
	fu(i,1,q,1,1){
		int op=read();
		if(op==1){
			int x=read(),t=read(),y=read();
			val[x][y]+=t;
			sz[x]+=t;
			stk[++ops]=(oper){1,x,y,t};
		}
		else if(op==2){
			int s=read();
			int u=uuu[s],v=vvv[s];
			if(eg.find(shxhs(u,v))==eg.end())continue;
			eg.erase(eg.find(shxhs(u,v))),eg.erase(eg.find(shxhs(v,u)));
			stk[++ops]=(oper){2,u,v,0};
		}
		else {
			int x=read(),t=read(),y=read();
			stk[++ops]=(oper){3,x,y,t};
		}
	}
	for(set<ll>::iterator i=eg.begin();i!=eg.end();i++)add(gU(*i),gV(*i));
	fu(i,1,n,1,1)if(bel[i]==i)dfs(i,i);
	while(ops){
		oper op=stk[ops--];
		if(op.tp==1){
			int x=op.x,y=op.y,t=op.t;
			int fa=fid(x);
			val[fa][y]-=t;
			sz[fa]-=t;
		}
		else if(op.tp==2){
			int u=op.x,v=op.y;
			if(fid(u)==fid(v))continue;
			int fau=fid(u),fav=fid(v);
			if(val[fau].size()<val[fav].size())swap(fau,fav),swap(u,v);
			int szv=val[fav].size();
			bel[fav]=fau;
			if(szv<=rtn){//brute force merge
				for(int i=hd[fav];i;i=nnxt[i])add1(fau,tt[i]);
				for(auto i:val[fav])val[fau][(i).first]+=(i).second;
			}
			else add1(fau,fav);
			sz[fau]+=sz[fav];
		}else{
			int x=op.x,y=op.y,t=op.t;
			int fa=fid(x);
			int res=dfs1(fa,fa,y);	//O(sqrt n)
			int S=sz[fa],Y=res;
			if(t>Y){ans[++anstop]=0;continue;}
			ans[++anstop]=(1LL*fac[Y]*fac[S-t]%MOD*inv(fac[S])%MOD*inv(fac[Y-t])%MOD);
		}
	}
	while(anstop)printf("%d\n",ans[anstop--]);
}