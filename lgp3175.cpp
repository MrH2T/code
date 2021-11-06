//vj465253k

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
inline int ct(int x){int sum=0;for(;x;x-=x&-x,sum++);return sum;}
int n;
double p[MAXN];
signed main(){
    n=read();
    fu(i,0,(1<<n)-1,1,1){
        scanf("%lf",&p[i]);
    }
    //this is FMT, which can calc subset-sum (in 'or')
    for(int i=1;i<(1<<n);i<<=1){
        for(int l=i<<1,j=0;j<(1<<n);j+=l){
            for(int k=0;k<i;k++)
                p[i+j+k]+=p[j+k];
        }
    }
    double res=0;
    fu(i,1,(1<<n)-1,1,1){
        if(1.0f-p[((1<<n)-1)^i]<1e-8)return printf("INF\n")&0;
        res+=(ct(i)&1?1:-1)/(1.0f-p[((1<<n)-1)^i]);
    }
    printf("%.8lf",res);
}