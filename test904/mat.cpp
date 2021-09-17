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
const int MAXN = 1050;
int n,m;
int a[MAXN][MAXN][2],now=0;

char s[1000050];
namespace Subtask2{
	int lt,rt,ut,dt,ar=1,br=1;
	void solve(){
		fu(i,1,m,1,1){
			if(s[i]=='L')lt+=ar;
			if(s[i]=='R')rt+=ar;
			if(s[i]=='U')ut+=br;
			if(s[i]=='D')dt+=br;
	//		if(s[i]=='I')ar=-ar;
	//		if(s[i]=='C')br=-br;
		}
		
		fu(i,1,n,1,1){
			fu(j,1,n,1,1)
				printf("%d ",a[((i+(ut-dt)-1)%n+n)%n+1][((j+lt-rt-1)%n+n)%n+1][now]);
			printf("\n");
		}
		exit(0);
	}
}
namespace Subtask1{
	void tl(){fu(i,1,n,1,1)fu(j,1,n,1,1)a[i][a[i][j][now]][now^1]=j;}
	void td(){fu(j,1,n,1,1)fu(i,1,n,1,1)a[a[i][j][now]][j][now^1]=i;}
	void rr(){fu(i,1,n,1,1)fu(j,1,n,1,1)a[i][j%n+1][now^1]=a[i][j][now];}
	void ll(){fu(i,1,n,1,1)fu(j,1,n,1,1)a[i][j][now^1]=a[i][j%n+1][now];}
	void dd(){fu(i,1,n,1,1)fu(j,1,n,1,1)a[i%n+1][j][now^1]=a[i][j][now];}
	void uu(){fu(i,1,n,1,1)fu(j,1,n,1,1)a[i][j][now^1]=a[i%n+1][j][now];}
	void pr(){fu(i,1,n,1,1){fu(j,1,n,1,1)printf("%d ",a[i][j][now]);puts("");}}
	void solve(){
		fu(i,1,m,1,1){
			if(s[i]=='L')ll();
			if(s[i]=='R')rr();
			if(s[i]=='U')uu();
			if(s[i]=='D')dd();
			if(s[i]=='I')tl();
			if(s[i]=='C')td();
			now^=1;
		}
		pr();
		exit(0);
	}
}

namespace Subtask3{
	char stk[1000050];
	int top=0;
	void tl(){fu(i,1,n,1,1)fu(j,1,n,1,1)a[i][a[i][j][now]][now^1]=j;}
	void td(){fu(j,1,n,1,1)fu(i,1,n,1,1)a[a[i][j][now]][j][now^1]=i;}
	void pr(){fu(i,1,n,1,1){fu(j,1,n,1,1)printf("%d ",a[i][j][now]);puts("");}}
	void solve(){
		fu(i,1,m,1,1){
			if(s[i]==stk[top])top--;
			else stk[++top]=s[i];
		}
		fu(i,max(1,top-top%6+1),top,1,1){
			if(stk[i]=='I')tl();
			else td();
			now^=1;
		}
		
		pr();
	}
}
signed main(){
//	freopen("mat1.in","r",stdin);
	n=read(),m=read();
	fu(i,1,n,1,1)fu(j,1,n,1,1)a[i][j][now]=read();
	scanf("%s",s+1);
	if(n<=10)Subtask1::solve();
	bool all1=true,all2=true;
	
	fu(i,1,m,1,1){
		if(s[i]=='I'||s[i]=='C')all1=false;
		if(s[i]!='I'&&s[i]!='C')all2=false;
	}
	
	if(all1)Subtask2::solve();
	else if(all2)Subtask3::solve();
	else printf("FU");
}
