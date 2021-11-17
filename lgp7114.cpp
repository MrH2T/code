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
const int MAXN = 1<<21;
int T,n;
char s[MAXN];
int nxt[MAXN];
void KMP(){
    memset(nxt,0,sizeof(nxt));
    int now=0,x=1;
    int len=strlen(s);
    while(x<len){
        if(s[now]==s[x])nxt[x++]=++now;
        else if(now)now=nxt[now-1];
        else nxt[x++]=0;
    }
}
bool buc[26];
int pre[MAXN],suf[MAXN],sum[MAXN];
signed main(){
    scanf("%d\n",&T);
    while(T--){
        scanf("%s\n",s);n=strlen(s);
        KMP();
        pre[0]=suf[n]=0;
        memset(buc,0,sizeof(buc));
        fu(i,0,n-1,1,1){
            buc[s[i]-'a']^=1;
            if(buc[s[i]-'a'])pre[i]=pre[i-1]+1;
            else pre[i]=pre[i-1]-1;
        }
        memset(buc,0,sizeof(buc));
        fd(i,n-1,0,1,1){
            buc[s[i]-'a']^=1;
            if(buc[s[i]-'a'])suf[i]=suf[i+1]+1;
            else suf[i]=suf[i+1]-1;
        }
        long long ans=0;
        memset(sum,0,sizeof(sum));
        fu(i,0,n-2,1,1){
            if(i){
                ans+=sum[suf[i+1]];
                fu(j,2*i+1,n-2,i+1,1){
                    if(((i+1)%(j+1-nxt[j])==0)&&((j+1)/(j+1-nxt[j])>1)){
                        ans+=sum[suf[j+1]];
                    }
                    else break;
                }
            }
            fu(j,pre[i],26,1,1)sum[j]++;
        }
        printf("%lld\n",ans);
    }
}