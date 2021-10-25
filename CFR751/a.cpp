#include<bits/stdc++.h>
#define rint int
#define fu(i,a,b,d,c) for(rint i=a;i<=b&&c;i+=d)
#define fd(i,a,b,d,c) for(rint i=a;i>=b&&c;i-=d)
using namespace std;
inline int read(){
    char c=0,f=1;int num=0;
    while(c<'0'||c>'9'&&c!='-')((c=getchar())=='-')&&(f=-f);
    while(c>='0'&&c<='9')num=(num<<1)+(num<<3)+(c^48),c=getchar();
    return num*f;
}
const int MAXN = 105;
int T;
char s[MAXN];
signed main(){
    scanf("%d\n",&T);
    while(T--){
        scanf("%s\n",s+1);
        char mini='z';
        int minid=0,len=strlen(s+1);
        fu(i,1,len,1,1){
            if(mini>=s[i]){
                mini=s[i],minid=i;
            }
        }
        printf("%c",mini),printf(" ");
        fu(i,1,minid-1,1,1)printf("%c",s[i]);
        fu(i,minid+1,len,1,1)printf("%c",s[i]);
        printf("\n");
        memset(s,0,sizeof(s));
    }
}