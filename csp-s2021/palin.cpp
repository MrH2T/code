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
int T,n,a[MAXN<<1],b[MAXN],ans[MAXN<<1];
int pos[MAXN],mat[MAXN<<1];
bool dfs(int now,int lb,int rb,int l,int r){
    if(now==n+1){
        fd(i,n,1,1,1){
            if(a[lb]==b[i])ans[(n<<1)-i+1]=0,lb++;
            else ans[(n<<1)-i+1]=1,rb--;
        }
        ans[n<<1]=0;
        fu(i,1,n<<1,1,1)putchar(ans[i]?'R':'L');
        putchar('\n');
        return 1;
    }
    if(lb<l&&(mat[lb]==l-1||mat[lb]==r+1)){
        ans[now]=0,b[now]=a[lb];
        return dfs(now+1,lb+1,rb,l-(mat[lb]==l-1),r+(mat[lb]==r+1));
    }
    if(rb>r&&(mat[rb]==l-1||mat[rb]==r+1)){
        ans[now]=1,b[now]=a[rb];
        return dfs(now+1,lb,rb-1,l-(mat[rb]==l-1),r+(mat[rb]==r+1));
    }
    return 0;
}
signed main(){
    T=read();
    while(T--){
        memset(pos,0,sizeof(pos));
        n=read();fu(i,1,n<<1,1,1)a[i]=read(),!pos[a[i]]?pos[a[i]]=i:mat[i]=pos[a[i]],mat[pos[a[i]]]=i;
        ans[1]=0,b[1]=a[1];
        if(dfs(2,2,n<<1,mat[1],mat[1]))continue;
        ans[1]=1,b[1]=a[n<<1];
        if(dfs(2,1,(n<<1)-1,mat[n<<1],mat[n<<1]))continue;
        printf("-1\n");
    }
    return 0;
}