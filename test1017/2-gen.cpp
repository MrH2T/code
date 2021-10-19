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
mt19937 rd(time(0));
signed main(){
    const int N = 5;
    printf("%d\n",N);
    fu(i,2,N,1,1){
        printf("%d ",llabs(rd())%(i-1)+1);
        printf("%d\n",llabs(rd())%10+1);
    }
    const int Q = 5;
    printf("%d\n",Q);
    fu(i,1,Q,1,1){
        printf("%d ",llabs(rd())%N+1);
        printf("%d\n",llabs(rd())%10+1);
    }
}