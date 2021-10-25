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
int random(int l,int r){
    return (llabs(rd())%(r-l+1))+l;
}
signed main(){
    const int L = 500, K = random(100,300),A = 50, B = 70, C = 95, D = 100;
    printf("%d %d\n",L,K);
    fu(i,1,L,1,1){
        int p=random(1,100);
        if(p<=A)putchar('?');
        else if(p<=B)putchar('*');
        else if(p<=C)putchar('(');
        else putchar(')');
    }
}