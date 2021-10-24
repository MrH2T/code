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
const int MAXN = 505, LJC = 1e9+7;
int n,k,cnt,pos[MAXN];
char c[MAXN];
int ans;
int stk[MAXN],top,cp[MAXN],ccf[MAXN];
void check(){
    // fu(i,1,n,1,1)putchar(c[i]);
    // putchar('\n');
    memset(stk,0,sizeof(stk)),top=0;
    memset(cp,0,sizeof(cp));
    memset(ccf,0,sizeof(ccf));
    int ps=0,cnt=0;
    if(c[1]=='*'||c[n]=='*')return;
    fu(i,1,n,1,1){
        if(c[i]=='*'){
            cnt++;
            if(cnt>k)return;
        }
    }
    fu(i,1,n,1,1){
        if(c[i]=='('){
            if(stk[top])ccf[stk[top]]=1;
            stk[++top]=i,ps++;
        }
        if(c[i]==')'){
            cp[stk[top--]]=i,ps--;
            stk[top+1]=0;
            if(ps<0)return;
        }
    }
    if(ps)return;
//    fu(i,1,n,1,1)printf("%d ",ccf[i]);putchar('\n');
    // fu(i,1,n,1,1)printf("%d ",cp[i]);putchar('\n');
    fu(i,1,n,1,1){
        if(c[i]=='('){
            if(ccf[i]&&c[i+1]=='*'&&c[cp[i]-1]=='*')return;
        }
    }
    ans++;
    // fu(i,1,n,1,1)putchar(c[i]);
    // putchar('\n');
    return;
}
void dfs(int now){
    if(now==cnt+1){return check();}
    c[pos[now]]='*';
    dfs(now+1);
    c[pos[now]]='(';
    dfs(now+1);
    c[pos[now]]=')';
    dfs(now+1);
}

signed main(){
    freopen("bracket.in","r",stdin);
    freopen("bracket.out","w",stdout);
    scanf("%d %d\n%s",&n,&k,c+1);
    fu(i,1,n,1,1)if(c[i]=='?')pos[++cnt]=i;
    dfs(1);
    printf("%d",ans%LJC);
    return 0;
}