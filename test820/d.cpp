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
#define send fflush(stdout)
int n,m1,m2,m3;
const int MAXN = 50050;
namespace SolveSub1{
	void solve(){
		printf("? %d ",n);
		fu(i,1,n,1,1)printf("%d ",i);
		printf("%d\n",n),send;
		read();
		int mxid=read(),m01=0,m02=0,m1=0;
		fu(i,1,n,1,1)if(i!=mxid){
			printf("! %d %d\n",mxid,i),send;
			int r=read();
			if(r==1)m1=i;
			if(r==0)if(m01)m02=i;else m01=i;
		}
		printf("! %d %d\n",m1,m01),send;
		int res=read();
		if(res==0){//m01 = 1
			printf("A ");
			fu(i,1,n,1,1){
				if(i==m01)printf("1 ");
				else if(i==m02)printf("2 ");
				else if(i==m1)printf("3 ");
				else if(i==mxid)printf("4 ");
			}
			printf("\n");
			send;
		}
		else { // m02 = 1
			printf("A ");
			fu(i,1,n,1,1){
				if(i==m01)printf("2 ");
				else if(i==m02)printf("1 ");
				else if(i==m1)printf("3 ");
				else if(i==mxid)printf("4 ");
			}
			printf("\n");
			send;
		}
		exit(0);
	}
}
namespace SolveAll{
	int mxid;
	vector<int> mods[MAXN];
	void solve(){
		printf("? %d ",n);
		fu(i,1,n,1,1)printf("%d ",i);
		printf("%d\n",n),send;
		read();mxid=read();
		fu(i,1,n,1,1)if(i!=mxid){
			printf("! %d %d\n",mxid,i),send;
			int r=read();
			mods[r].push_back(i);
		}
		
		exit(0);
	}
}
signed main(){
	n=read(),m1=read(),m2=read(),m3=read();
	if(n==4)SolveSub1::solve();
	SolveAll::solve();
}

