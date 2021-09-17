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
const int MAXN = 100050;
int n,m;

namespace Subtask1{
	const int MAXK = 20;
	int root[MAXN],fa[MAXN][21],dep[MAXN];
	void dfs1(int p){
		if(p>n)return;
		fa[p][0]=p>>1,dep[p]=dep[p>>1]+1;
		fu(i,1,MAXK,1,1)fa[p][i]=fa[fa[p][i-1]][i-1];
		dfs1(p<<1),dfs1(p<<1|1);
	}
	void dfs2(int p,int k){
		if(p>n)return;
		if(root[p<<1]==root[p])dfs2(p<<1,k);
		if(root[p<<1|1]==root[p])dfs2(p<<1|1,k);
		root[p]=k;
	}
	int lca(int x,int y){
		if(root[x]!=root[y])return 0;
		if(dep[x]<dep[y])swap(x,y);
		fd(i,MAXK,0,1,1)if(dep[fa[x][i]]>=dep[y])x=fa[x][i];
		if(x==y)return y;
		fd(i,MAXK,0,1,1){
			if(fa[x][i]!=fa[y][i])x=fa[x][i],y=fa[y][i];
		}
		return fa[x][0];
	}
	void solve(){
		fu(i,1,n,1,1)root[i]=1;
		dfs1(1);
		fu(_,1,m,1,1){
			char op;int x;
			scanf("%c %d\n",&op,&x);
			if(op=='-'){
				dfs2(x,x);
			}
			else{
				int sum=0;
				fu(i,1,n,1,1){
					fu(j,i+1,n,1,1){
						if(root[i]==root[j]){
							int lc=lca(i,j);
							if(dep[i]+dep[j]-2*dep[lc]<=x)sum++;
						}
					}
				}
				printf("%d\n",sum);
			}
		}
	}
}
namespace Subtask2{
	int f[MAXN<<2][50];
	void dfs(int p,int k){
		if(p>n)return;
		dfs(p<<1,k),dfs(p<<1|1,k);
		f[p][k]=f[p<<1][k-1]+f[p<<1|1][k-1]+f[p>>1][k-1]-f[p][k-2];
	}
	void solve(){
		fu(i,1,n,1,1)f[i][0]=1;
		fu(i,1,n,1,1)f[i][1]=((i>>1)>0)+((i<<1)<=n)+((i<<1|1)<=n);
		fu(i,2,40,1,1)dfs(1,i);
		fu(_,1,m,1,1){
			char op;int x;
			scanf("%c %d\n",&op,&x);
			if(op=='?'){
				int ans=0;
				fu(i,1,n,1,1)ans+=f[i][x];
				printf("%d\n",ans>>1);
			}
			else{
				exit(0);
			}
		}
	}
}

signed main(){
	scanf("%d %d\n",&n,&m);
//	if(n<=50){Subtask1::solve();return 0;}
	Subtask2::solve();
	return 0;
}
/*
5 5
? 2
- 2
? 2
- 5
? 2

*/
