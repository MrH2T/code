#include<bits/stdc++.h>
#define int long long
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
int c88(int t){
	int res;
	if(t==1||t==2||t==5)res=8;
	if(t==3)res=4;
	if(t==4)res=2;
	if(t==0)res=6;
	return res;
}
int c77(int t){
	int res;
	if(t==1||t==2||t==5)res=7;
	if(t==3)res=9;
	if(t==4)res=3;
	if(t==0)res=1;
	return res;
}
int c33(int t){
	int res;
	if(t==1||t==2||t==5)res=3;
	if(t==3)res=9;
	if(t==4)res=7;
	if(t==0)res=1;
	return res;
}
int c22(int t){
	int res;
	if(t==1||t==2||t==5)res=2;
	if(t==3)res=4;
	if(t==4)res=8;
	if(t==0)res=6;
	return res;
}
int n,m,k;
signed main(){
	n=read(),m=read(),k=read();
	if(k<=1000000){
		if(k==1)return printf("%lld",n)&0;
		if(k==2)return printf("%lld",m)&0;
		fu(i,3,k,1,1){
			int t=m;
			m=n*m%10,n=t;
		}
		printf("%lld",m);
		return 0;
	}
	if(n==0)printf("%lld",k==2?m:0);
	else if(m==0)printf("%lld",k==1?n:0);
	else if(m==1)printf("%lld",k%2?n:1);
	else if(n==1){
		if(m==2){
			int t=(k-1)%4,res=1;
			if(t==1)res=2;
			if(t==2)res=4;
			if(t==3)res=8;
			if(t==0)res=6;
			if(k==1)res=1;
			printf("%lld",res);
		}
		if(m==3){
			int t=(k%4),res=1;
			if(t==1)res=1;
			if(t==2)res=3;
			if(t==3)res=9;
			if(t==0)res=7;
			printf("%lld",res);
		}
		if(m==4){
			int t=(k-2)%2;
			printf("%lld",k==1?1:k==2?4:t==1?4ll:6ll);
		}
		if(m==5||m==6)printf("%lld",k==1?1ll:m);
		if(m==7){
			int t=(k-2)%4,res=1;
			if(t==1)res=9;
			if(t==2)res=3;
			if(t==3)res=7;
			if(t==0)res=1;
			printf("%lld",k==1?1:k==2?7ll:res);
		}
		if(m==8){
			int t=(k-1)%4,res=1;
			if(t==1||t==2||t==5)res=8;
			if(t==3)res=4;
			if(t==4)res=2;
			if(t==0)res=6;
			printf("%lld",k==1?1:res);
		}
		if(m==9){
			int t=k%3,res=1;
			if(t==1)res=1;
			else res=9;
			printf("%lld",res);
		}
	}
	else if(n==2){
		if(m==2){
			int t=k%6,res=1;
			if(t==1||t==2||t==5)res=2;
			if(t==3)res=4;
			if(t==4)res=8;
			if(t==0)res=6;
			printf("%lld",res);
		}
		if(m==3){
			int t=(k-3)%6,res=1;
			if(t==1||t==2||t==5)res=8;
			if(t==3)res=4;
			if(t==4)res=2;
			if(t==0)res=6;
			printf("%lld",k==1?2:k==2?3:k==3?6:res);
		}
		if(m==4){
			int t=(k-4)%6,res=1;
			if(t==1||t==2||t==5)res=8;
			if(t==3)res=4;
			if(t==4)res=2;
			if(t==0)res=6;
			printf("%lld",k==1?2:k==2?4:k==3?8:k==4?6:res);
		}
		if(m==5){
			printf("%lld",k>2?0:k==1?2ll:5ll);
		}
		if(m==6){
			printf("%lld",k%2?2ll:6ll);
		}
		if(m==7){
			int t=(k-2)%6,res=1;
			if(t==3||t==5||t==0)res=2;
			if(t==1)res=4;
			if(t==2)res=8;
			if(t==4)res=6;
			printf("%lld",k==1?2:k==2?7:res);
		}
		if(m==8){
			int t=(k-3)%6,res=1;
			if(t==1||t==2||t==5)res=8;
			if(t==3)res=4;
			if(t==4)res=2;
			if(t==0)res=6;
			printf("%lld",k==1?2ll:k==2?8ll:k==3?6ll:res);
		}
		if(m==9){
			int t=(k-5)%6,res=1;
			if(t==1||t==2||t==4)res=2;
			if(t==3)res=4;
			if(t==5)res=8;
			if(t==0)res=6;
			printf("%lld",k==1?2ll:k==2?9ll:k==3?8ll:k==4?2ll:k==5?6ll:res);
		}
	}
	else if(n==3){
		if(m==2){
			int t=(k-1)%2;
			printf("%lld",k==1?3ll:t?2ll:6ll);
		}
		else if(m==3){
			int t=k%6,res=1;
			if(t==1||t==2||t==5)res=3;
			if(t==3)res=9;
			if(t==4)res=7;
			if(t==0)res=1;
			printf("%lld",res);
		}
		else if(m==4){
			int res=c88((k-5)%6);
			printf("%lld",k==1?3ll:k==2?4ll:k==3?2ll:k==4?8ll:k==5?6ll:res);
		}
		else if(m==5){
			printf("%lld",k>1?5ll:3ll);
		}
		else if(m==6){
			int res=c88((k-2)%6);
			printf("%lld",k==1?3ll:k==2?6ll:res);
		}
		else if(m==7){
			int res=c77((k-3)%6);
			printf("%lld",k==1?3ll:k==2?7ll:k==3?1ll:res);
		}
		else if(m==8){
			int res=c88((k-6)%6);
			printf("%lld",k==1?3ll:k==2?8ll:k==3?4ll:k==4?2ll:k==5?8ll:k==6?6ll:res);
		}
		else if(m==9){
			int res=c33((k-5)%6);
			printf("%lld",k==1?3ll:k==2?9ll:k==3?7ll:k==4?3ll:k==5?1ll:res);
		}
	}
	else if(n==4){
		if(m==2){
			int res=c88((k-4)%6);
			printf("%lld",k==1?4ll:k==2?2ll:k==3?8ll:k==4?6ll:res);
		}
		if(m==3){
			int res=c22((k-4)%6);
			printf("%lld",k==1?4ll:k==2?3ll:k==3?2ll:k==4?6ll:res);
		}
		if(m==4){
			int t=k%3;
			printf("%lld",t==1?4ll:t==2?4ll:6ll);
		}
		if(m==5){
			printf("%lld",k>2?0ll:k==1?4ll:5ll);
		}
		if(m==6){
			int t=(k-2)%3;
			printf("%lld",k==1?4ll:k==2?6ll:t==1?4ll:t==2?4ll:6ll);
		}
		if(m==7){
			int res=c88((k-4)%6);
			printf("%lld",k==1?4ll:k==2?7:k==3?8:k==4?6:res);
		}
		if(m==8){
			int res=c22((k-4)%6);
			printf("%lld",k==1?4:k==2?8:k==3?2:k==4?6:res);
		}
		if(m==9){
			int t=(k-3)%3;
			printf("%lld",k==1?4:k==2?9:k==3?6:t==1?4:t==2?4:6);
		}
	}
	else if(n==5){
		if(m==2||m==4||m==6||m==8){
			printf("%lld",k==1?5:k==2?m:0);
		}
		if(m==3||m==5||m==7||m==9)printf("%lld",k==1?5:k==2?m:5);
	}
	else if(n==6){
		if(m==2){
			int res=c22((k-1)%6);
			printf("%lld",k==1?6:res);
		}
		if(m==3){
			int res=c88((k-7)%6);
			printf("%lld",k==1?6:k==2?3:k==3?8:k==4?4:k==5?2:k==6?8:k==7?6:res);
		}
		if(m==4){
			int t=k%3;
			printf("%lld",t==1?6:4);
		}
		if(m==5){printf("%lld",k==1?6:k==2?5:0);}
		if(m==6)printf("6");
		if(m==7){
			int res=c22((k-7)%6);
			printf("%lld",k==1?6:k==2?7:k==3?2:k==4?4:k==5?8:k==6?2:k==7?6:res);
		}
		if(m==8){
			int res=c88((k-1)%6);
			printf("%lld",k==1?6:res);
		}
		if(m==9){
			int t=(k-2)%3;
			printf("%lld",k==1?6:k==2?9:t==2?6:4);
		}
	}
	if(n==7){
		if(m==2){
			int res=c22((k-6)%6);
			printf("%lld",k==1?7:k==2?2:k==3?4:k==4?8:k==5?2:k==6?6:res);
		}
		if(m==3){
			int res=c33((k-3)%6);
			printf("%lld",k==1?7:k==2?3:k==3?1:res);
		}
		if(m==4){
			int res=c22((k-5)%6);
			printf("%lld",k==1?7:k==2?4:k==3?8:k==4?2:k==5?6:res);
		}
		if(m==5)printf("%lld",k==1?7:5);
		if(m==6){
			int res=c22((k-2)%6);
			printf("%lld",k==1?7:k==2?6:res);
		}
		if(m==7){
			printf("%lld",c77(k%6));
		}
		if(m==8){
			int res=c88((k-3)%6);
			printf("%lld",k==1?7:k==2?8:k==3?6:res);
		}
		if(m==9){
			int res=c77((k-5)%6);
			printf("%lld",k==1?7:k==2?9:k==3?3:k==4?7:k==5?1:res);
		}
	}
	if(n==8){
		if(m==2){
			int res=c22((k-3)%6);
			printf("%lld",k==1?8:k==2?2:k==3?6:res);
		}
		if(m==3){
			int res=c88((k-6)%6);
			printf("%lld",k==1?8:k==2?3:k==3?4:k==4?2:k==5?8:k==6?6:res);
		}
		if(m==4){
			int res=c88((k-5)%6);
			printf("%lld",k==1?8:k==2?4:k==3?2:k==4?8:k==5?6:res);
		}
		if(m==5)printf("%lld",k==1?8:k==2?5:0);
		if(m==6){
			int res=c88((k-2)%6);
			printf("%lld",k==1?8:k==2?6:res);
		}
		if(m==7){
			int res=c22((k-3)%6);
			printf("%lld",k==1?8:k==2?7:k==3?6:res);
		}
		if(m==8){
			printf("%lld",c88(k%6));
		}
		if(m==9){
			int res=c88((k-5)%6);
			printf("%lld",k==1?8:k==2?9:k==3?2:k==4?8:k==5?6:res);
		}
	}
	else if(n==9){
		if(m==2){
			int res=c88((k-4)%6);
			printf("%lld",k==1?9:k==2?2:k==3?8:k==4?6:res);
		}
		if(m==3){
			int res=c77((k-4)%6);
			printf("%lld",k==1?9:k==2?3:k==3?7:k==4?1:res);
		}
		if(m==4){
			int t=(k-1)%3;
			printf("%lld",k==1?9:t==2?6:4);
		}
		if(m==5)printf("%lld",k==1?9:5);
		if(m==6){
			int t=(k-1)%3;
			printf("%lld",k==1?9:t==1?6:4);
		}
		if(m==7){
			int res=c33((k-4)%6);
			printf("%lld",k==1?9:k==2?7:k==3?3:k==4?1:res);
		}
		if(m==8){
			int res=c22((k-4)%6);
			printf("%lld",k==1?9:k==2?8:k==3?2:k==4?6:res);
		}
		if(m==9){
			int t=k%3;
			printf("%lld",t==0?1:9);
		}
	}
}
