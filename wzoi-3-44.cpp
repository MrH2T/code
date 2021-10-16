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
int n;
signed main(){
    int T=read();
    while(T--){
        n=read();
        int sm=0,no=0;
        fu(i,1,n,1,1){
            int x=read();no|=x>1;
            sm^=x;
        }
        if(sm==0&&!no||(no&&sm))printf("John\n");
        else printf("Brother\n");
    }
}