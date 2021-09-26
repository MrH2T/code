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
const int MOD = 1e9+7;
const int MAXN = 1000050;
int n,cnt;
int head[MAXN],nxt[MAXN],to[MAXN];
map<string,bool> mp;
bool bk[MAXN];
void dfs(int p,string s){
	if(mp[s])return;
	mp[s]=1;
	for(int i=head[p];i;i=nxt[i]){
		if(!bk[to[i]])
			bk[p]=1,dfs(to[i],s+char(to[i]+'0')),bk[p]=0;
	}
}
void add(int x,int y){nxt[++cnt]=head[x],head[x]=cnt,to[cnt]=y;}

int table[450]={1,1,9,245,126565,0};

signed main(){
	n=read();
	
	if(n<=4)return printf("%d",table[n])&0;
	
	
	
	
	fu(i,1,(1<<n)-1,1,1){
		int fa=i>>1;
		while(fa){
			add(i,fa);add(fa,i);
			fa>>=1;
		}
	}
	fu(i,1,(1<<n)-1,1,1)add(0,i);
	dfs(0,"");
	printf("%d ",mp.size()-1);
}
