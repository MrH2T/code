#include<bits/stdc++.h>
#define rint register int
#define fu(i,a,b,d,c) for(rint i=a;i<=b&&c;i+=d)
#define fd(i,a,b,d,c) for(rint i=a;i>=b&&c;i-=d)
using namespace std;
typedef long long ll;
inline int read(){
    char c=0,f=1;int num=0;
    while(c<'0'||c>'9'&&c!='-')((c=getchar())=='-')&&(f=-f);
    while(c>='0'&&c<='9')num=(num<<1)+(num<<3)+(c^48),c=getchar();
    return num*f;
}
const int MAXN = 105, MAXM = 2505;
int n,m,k;
struct Mat{
    ll a[MAXN][MAXN];
    Mat(){memset(a,0,sizeof(a));}
    inline ll* operator[](int ind){return a[ind];}
    void init(){memset(a,0x3f,sizeof(a));fu(i,1,n,1,1)a[i][i]=0;}
    Mat operator*(Mat b){
        Mat c;memset(c.a,0x3f,sizeof(c.a));
        fu(i,1,n,1,1)fu(j,1,n,1,1)fu(k,1,n,1,1)c[i][j]=min(c[i][j],a[i][k]+b[k][j]);
        return c;
    }
}base0,base1;
struct edge{int u,v,w;}e[MAXM];

void floyd(){
    fu(k,1,n,1,1)fu(i,1,n,1,1)fu(j,1,n,1,1)
        base0[i][j]=min(base0[i][j],base0[i][k]+base0[k][j]);
}
void floyd1(){
    memcpy(base1.a,base0.a,sizeof(base0.a));
    fu(k,1,m,1,1)fu(i,1,n,1,1)fu(j,1,n,1,1){
        base1[i][j]=min(base1[i][j],base0[i][e[k].u]+base0[e[k].v][j]-e[k].w);
    }
}
Mat qp(Mat a,int p){
    Mat res=base0;
    for(;p;p>>=1,a=a*a)(p&1)&&(res=res*a,0);
    return res;
}
signed main(){
    n=read(),m=read(),k=read();
    memset(base0.a,0x3f,sizeof(base0.a));
    fu(i,1,n,1,1)base0[i][i]=0;
    fu(i,1,m,1,1){
        int u=read(),v=read(),w=read();
        base0[u][v]=w,e[i]=(edge){u,v,w};
    }
    floyd(),floyd1();
    printf("%lld",(qp(base1,k))[1][n]);
}