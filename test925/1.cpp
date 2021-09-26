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
const int MAXN = 200050, P = 19260817;
typedef unsigned long long ull;
int _min(int a,int b){return a<b?a:b;}
string s,t[12];
bool cmp1(string a,string b){return a<b;}
bool cmp(string a,string b){return a.size()<b.size();}
int n,m,a[MAXN],lb[MAXN*10],rb[MAXN*10],its;

ull ppow[MAXN],hss[MAXN],hst[12];

int mn[MAXN][20],kv[MAXN];
int getmn(int l,int r){return _min(mn[l][kv[r-l]],mn[r-(1<<kv[r-l])+1][kv[r-l]]);}
int f[MAXN*10];
signed main(){
    freopen("testn2.txt","r",stdin);
//	freopen("wzadx.in","r",stdin);
//	freopen("wzadx.out","w",stdout);
	scanf("%d %d",&n,&m);
	ppow[0]=1;fu(i,1,n,1,1)ppow[i]=ppow[i-1]*P;
	cin>>s;
	hss[0]=s[0];fu(i,1,n-1,1,1)hss[i]=hss[i-1]+s[i]*ppow[i];
	
	fu(i,0,n-1,1,1)scanf("%d ",&a[i]);
	fu(i,1,m,1,1){
		cin>>t[i];
	}
	sort(t+1,t+m+1,cmp1);
	m=unique(t+1,t+m+1)-t-1;
	sort(t+1,t+m+1,cmp);
	fu(i,1,m,1,1){
		int sz=t[i].size();
		fu(j,0,sz-1,1,1)hst[i]=hst[i]+ppow[j]*t[i][j];
	}
	fu(i,0,n-1,1,1){
		fu(j,1,m,1,1){int sz=t[j].size();
			if(i+sz-1>=n)break;
			if(hss[i+sz-1]-(!i?0:hss[i-1])==hst[j]*ppow[i]){
				lb[++its]=i;
				rb[its]=i+sz-1;
			}
		}
	}
	// f[i] = min {f[k]+MinA(l[i],min(r[i],r[k+1]))}, r[k+1]>=l[i]
	fu(i,0,n-1,1,1)mn[i][0]=a[i];
	int logn=(int)log2(n)+1;
	fu(k,1,logn,1,1)fu(i,0,n-1,1,1)if(i+(1<<k-1)<n)mn[i][k]=_min(mn[i][k-1],mn[i+(1<<k-1)][k-1]);
	kv[1]=0;
	fu(i,2,n,1,1){
		if(!(i&(i-1)))kv[i]=kv[i-1]+1;
		else kv[i]=kv[i-1];
	}
	memset(f,0x3f,sizeof(f));
	f[0]=0;f[1]=getmn(lb[1],rb[1]);
	fu(i,2,its,1,1){
		int mj=rb[i];
		fd(j,i,1,1,1){
			if(rb[j]<mj)mj=rb[j];
			if(mj<lb[i])break;
			f[i]=_min(f[i],f[j-1]+getmn(lb[i],mj));
		}
	}
	printf("%d",f[its]);
	return 0;
}