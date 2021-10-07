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
#define printf(args...) std::printf(args),fflush(stdout);
void askdfn(int x){printf("dfn %d\n",x);}
void askdis(int x,int y){printf("dis %d %d\n",x,y);}
void askdel(){printf("del\n");}
void prtans(int x){printf("! %d",x);}

const int MAXN = 5050;
int n;
int deg[MAXN];

signed main(){
	int one=0;
	bool flag=0;
	n=read();
	fu(i,1,n,1,1){
		deg[i]=read();
		if(deg[i]>2)flag=false;
		if(deg[i]==1)one++;
		if(one>2)flag=false;
	}
	if(n==1){
		prtans(0);
		return 0;
	}
	if(n==2){askdis(1,2),
		prtans(read());
		return 0;
	}
	flag=one==2;
	while(!flag){
		askdel();
		n=read();
		if(n==1){
			prtans(0);
			return 0;
		}
		if(n==2){askdis(1,2),
			prtans(read());
			return 0;
		}
		one=0;
		flag=true;
		fu(i,1,n,1,1){
			deg[i]=read();
			if(deg[i]>2){flag=false;}
			if(deg[i]==1)one++;
			if(one>2){flag=false;}
		}
		flag=one==2;
		fk:;
	}
	int p1=0,p2=0;
	fu(i,1,n,1,1){
		if(deg[i]==1){
			if(p1)p2=i;
			else p1=i;
		}
	}
	askdis(p1,p2);
	prtans(read());
}

