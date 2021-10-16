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
const int MAXN = 100050 , MOD = 998244353LL;
const int inv100  = 828542813LL;
int n;
int f[MAXN][26];
int p[MAXN];
char s[MAXN];
signed main(){
    scanf("%d\n%s",&n,s+1);
    fu(i,1,n,1,1)p[i]=read()*inv100%MOD;
    fu(i,1,n,1,1){
        f[i][s[i]-'a']=(f[i-1][s[i]-'a']*p[i]%MOD+(MOD+1-p[i])%MOD)%MOD;
        fu(j,'a','z',1,1){
            f[i][s[i]-'a']=(f[i][s[i]-'a']+f[i-1][j-'a']*(MOD+1-p[i])%MOD)%MOD;
            if(j!=s[i])f[i][j-'a']=f[i-1][j-'a'];
        }
    }
    int ans=0;
    fu(i,'a','z',1,1)ans=(ans+f[n][i-'a'])%MOD;
    printf("%lld",(ans+1)%MOD);
}