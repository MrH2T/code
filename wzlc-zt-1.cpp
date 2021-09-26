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
const int MAXN = 5000050, MOD = 1e9+7;
int n,m,a[MAXN],f[MAXN][11][2];
char s[MAXN];
bool beleaf(int p){return (p<<1)>n;}
bool inbound(int p){return p<=n;}
#define ls p<<1
#define rs p<<1|1
void dfs(int p){
    f[p][0][0]=1;
    if(!a[p])fu(i,1,m,1,1)f[p][i][1]=1;
    if(!beleaf(p)){
        dfs(ls);
        if(inbound(rs))dfs(rs);
    	fd(i,m,1,1,1){
    		fu(j,1,i,1,1){
    			if(j>0)f[p][i][0]=(f[p][i][0]+1LL*f[p][i-j][0]*(f[ls][j][0]+f[ls][j][1])%MOD)%MOD;
				if(!a[p]&&j<i)
					f[p][i][1]=(f[p][i][1]+1LL*f[p][i-j][1]*f[ls][j][0]%MOD)%MOD;
			}
		}
		if(p==1){
			fu(i,0,m,1,1)printf("%d/%d ",f[p][i][0],f[p][i][1]);
			puts("");
		}
		if(inbound(rs))
		fd(i,m,1,1,1){
    		fu(j,1,i,1,1){
    			if(j>0)f[p][i][0]=(f[p][i][0]+1LL*f[p][i-j][0]*(f[rs][j][0]+f[rs][j][1])%MOD)%MOD;
				if(!a[p]&&j<i)
					f[p][i][1]=(f[p][i][1]+1LL*f[p][i-j][1]*f[rs][j][0]%MOD)%MOD;
			}
		}
    }
}
signed main(){
    scanf("%d %d\n",&n,&m);
    scanf("%s",s+1);
    fu(i,1,n,1,1)a[i]=s[i]-'0';
    dfs(1);
    fu(i,1,n,1,1){
    	printf("%d: ",i);
    	fu(j,0,m,1,1)printf("%d:%d/%d ",j,f[i][j][0],f[i][j][1]);
    	puts("");
	}
    
    printf("%d",(f[1][m][0]+f[1][m][1]%MOD));
}
