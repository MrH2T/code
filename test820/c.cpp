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
const int MAXN = 1050,MAXM = 1000500;
int n,m;
int cnt,head[MAXN],nxt[MAXM<<1],to[MAXM<<1];
void add(int u,int v){nxt[++cnt]=head[u],head[u]=cnt,to[cnt]=v;}
struct data{int id,val;bool operator<(data b)const{return val<b.val;};}deg[MAXN];
namespace Solve2{
	bool vis[MAXN];
	int ans[MAXN];
	void solve(){
		sort(deg+1,deg+n+1);
		fu(i,1,n,1,1){
			if(!vis[deg[i].id]){
				int u=deg[i].id;
				for(int j=head[u];j;j=nxt[j])vis[to[j]]=1;
				ans[++ans[0]]=u;
			}
			if(ans[0]==n/3){
				printf("2\n");
				fu(j,1,ans[0],1,1)printf("%d ",ans[j]);
				exit(0);
			}
		}
	}
}
namespace Solve1{
	void solve(){
		
	}
}
signed main(){
	n=read(),m=read();
	fu(i,1,n,1,1)deg[i].id=i;
	fu(i,1,m,1,1){
		int u=read(),v=read();
		add(u,v),add(v,u);
		deg[u].val++,deg[v].val++;
	}
	Solve2::solve();
	Solve1::solve();
	printf("Poor lnlhm!");
}

