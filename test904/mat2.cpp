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
struct dat{
	int nm[4];
	int& operator[](const int ind){return nm[ind];}
}a[MAXN*MAXN];
int b[MAXN][MAXN];
bool cmp(dat a,dat b){
	return a[1]!=b[1]?a[1]<b[1]:a[2]<b[2];
}
int de[4],id[4]={0,1,2,3};
int n,m;
void mod(int &x){x>n?x-=n:0;}
char s[1000050];
signed main(){
//	freopen("mat3.in","r",stdin);
	int T=read();
	while(T--){
		n=read(),m=read();
		de[1]=de[2]=de[3]=0;
		id[1]=1,id[2]=2,id[3]=3;
		fu(i,1,n,1,1)fu(j,1,n,1,1)a[(i-1)*n+j]=(dat){{0,i,j,read()}};
		scanf("%s\n",s+1);
		fu(i,1,m,1,1){
			if(s[i]=='U')mod(de[1]+=n-1);
			if(s[i]=='D')mod(++de[1]);
			if(s[i]=='L')mod(de[2]+=n-1);
			if(s[i]=='R')mod(++de[2]);
			if(s[i]=='I')swap(id[3],id[2]),swap(de[3],de[2]);
			if(s[i]=='C')swap(id[3],id[1]),swap(de[3],de[1]);
		}
		fu(i,1,n*n,1,1){
			int b1,b2,b3;
			mod(b1=a[i][id[1]]+de[1]);
			mod(b2=a[i][id[2]]+de[2]);
			mod(b3=a[i][id[3]]+de[3]);
			b[b1][b2]=b3;
		}
		fu(i,1,n,1,1){
			fu(j,1,n,1,1)printf("%d ",b[i][j]);
			puts("");
		}
		puts("");
	}
}
