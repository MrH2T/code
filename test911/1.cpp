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
const int dir[4][2]={{0,-1},{0,1},{1,0},{-1,0}};
int n,m,a[1050][1050];
char s[1050][1050];
#define toV(x,y) (x-1)*m+y
#define toX(v) v/m+1
#define toY(v) (v-1)%m+1
inline int aabs(int x){return x<0?-x:x;}
int dis[1050][1050];
int q[1050*1050],l,r;
void init(){
	memset(dis,-1,sizeof(dis));
	l=1,r=0;
	fu(i,1,n,1,1)fu(j,1,m,1,1)if(s[i][j]=='.')dis[i][j]=0,q[++r]=toV(i,j);
	while(l<=r){
		int x=toX(q[l]),y=toY(q[l]);l++;
		fu(p,0,3,1,1){
			int dx=x+dir[p][0],dy=y+dir[p][1];
			if(dx>=1&&dx<=n&&dy>=1&&dy<=m&&!~dis[dx][dy])
			{
				dis[dx][dy]=dis[x][y]+1;
				q[++r]=toV(dx,dy);
			}
		}
	}
}
int vis[1050][1050];
bool check(int rad){
	memset(vis,-1,sizeof(vis));l=1,r=0;
	fu(i,1,n,1,1)fu(j,1,m,1,1)if(dis[i][j]>=rad)vis[i][j]=rad-1,q[++r]=toV(i,j);
	while(l<=r){
		int x=toX(q[l]),y=toY(q[l]);l++;
		if(vis[x][y]==0)break;
		fu(p,0,3,1,1){
			int dx=x+dir[p][0],dy=y+dir[p][1];
			if(dx>=1&&dx<=n&&dy>=1&&dy<=m&&!~vis[dx][dy]){
				q[++r]=toV(dx,dy);
				vis[dx][dy]=vis[x][y]-1;
			}
		}
	}
	fu(i,1,n,1,1)fu(j,1,m,1,1)if(dis[i][j]&&!~vis[i][j])return false;
	return true;
}

signed main(){
//	freopen("1.in","r",stdin);
	
	scanf("%d%d\n",&n,&m);
	fu(i,1,n,1,1)scanf("%s\n",s[i]+1);
	init();
	int l=0,r=(min(n,m)>>1);
	while(l<r){
		int mid=l+r+1>>1;
		if(check(mid))l=mid;
		else r=mid-1;
	}
	printf("%d",l-1);
}
