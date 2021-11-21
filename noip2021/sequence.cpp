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
const int MAXM = 120, MAXN = 35,LJC = 998244353;
inline int popcnt(int x){
    int sum=0;
    while(x)x-=x&-x,sum++;
    return sum;
}
int v[MAXM],n,m,k;
int f[31<<13][31];
signed main(){
    freopen("sequence.in","r",stdin);
    freopen("sequence.out","w",stdout);

    n=read(),m=read(),k=read();
    fu(i,0,m,1,1)v[i]=read();

    //i now have a 50 pts program based on dp that enumerating the number-value
    //      , which is  O(n^2logn * 2^m)
    //if i want to ac it, i have to expand it to binary-bits
    //i now have an idea that maybe there's an algorithm of O(n^2 * m)
    //10:21 : let's try this
    //10:46 : it's fake. i've deleted it
    //10:50 : i'll give it up if i have no further idea until 11:10
    //11:07 : i'm giving up. i will use my 50-pts program and go for t4's subtask
    //12:50 : i can't rush it out
    for(int i=1,b=0;i<=(n<<m)&&b<=m;i<<=1,b++){
        f[i][1]=v[b];
    }
    fu(j,2,n,1,1)
        fu(i,1,(n<<m),1,1){
            for(int l=1,b=0;l<=i&&b<=m;l<<=1,b++){
                f[i][j]=(1ll*f[i][j]+1ll*v[b]*f[i-l][j-1])%LJC;
            }
        }
    int ans=0;
    fu(i,n,(n<<m),1,1){
        if(popcnt(i)<=k)ans=(ans+f[i][n])%LJC;
    }
    printf("%d\n",ans);
    return 0;
}