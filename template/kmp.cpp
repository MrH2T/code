// kmp algorithm
// O(n) find prefix-suffix matching length

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
const int MAXN = 1e6+50;
namespace KMP{
    int nxt[MAXN];
    int* solve(const char *s){
        memset(nxt,0,sizeof(nxt));
        int len=strlen(s);
        int now=0,x=1;
        while(x<len){
            if(s[now]==s[x])nxt[x++]=++now;
            else if(now)now=nxt[now-1];
            else nxt[x++]=0;
        }
        return nxt;
    }
}
char s[MAXN];
signed main(){
    scanf("%s",s);
    int len=strlen(s);
    int *res=KMP::solve(s);
    fu(i,0,len-1,1,1)printf("%d ",res[i]);
}