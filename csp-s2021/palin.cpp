#include<bits/stdc++.h>
#define rint register int
#define fu(i,a,b,d,c) for(rint i=a;i<=b&&c;i+=d)
#define fd(i,a,b,d,c) for(rint i=a;i>=b&&c;i-=d)
using namespace std;
inline int read(){
    char c=0,f=1;int num=0;
    while(c<'0'||c>'9')((c=getchar())=='-')&&(f=-f);
    while(c>='0'&&c<='9')num=(num<<1)+(num<<3)+(c^48),c=getchar();
    return num*f;
}
const int MAXN = 500050;
int T,n;
int a[MAXN<<1];
int b[MAXN<<1];
int tmp[MAXN<<1];
bool check(){
    int lp=1,rp=2*n;
    fu(i,1,2*n,1,1)tmp[i]=(b[i])?a[rp--]:a[lp++];
    fu(i,1,n,1,1)if(tmp[i]!=tmp[2*n-i+1])return false;
    return true;
}
bool flag=0;
void dfs(int now){
    if(now==2*n+1){
        if(check()){
            fu(i,1,2*n,1,1)putchar(b[i]?'R':'L');
            putchar('\n');
            flag=1;
        }
        return ;
    }
    if(flag)return;
    b[now]=0;
    dfs(now+1);
    if(flag)return;
    b[now]=1;
    dfs(now+1);
}

signed main(){
    freopen("palin.in","r",stdin);
    freopen("palin.out","w",stdout);
    T=read();
    while(T--){flag=0;
        n=read();fu(i,1,2*n,1,1)a[i]=read();
        dfs(1);
        if(!flag)printf("-1\n");
    }
    return 0;
}