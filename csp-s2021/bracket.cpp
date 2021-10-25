#include<bits/stdc++.h>
#define rint int
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
int n,k,f[MAXN][MAXN],g[MAXN][MAXN],h[MAXN][MAXN],w[MAXN][MAXN];
//%czq

/*
f: answer   
g: answer of prefix '*'    (SA)
h: answer of suffix '*'    (AS)
w: answer of 'when l and r are paired' (A)
*/


char c[MAXN];
bool pl(int i){return c[i]=='('||c[i]=='?';}
bool pr(int i){return c[i]==')'||c[i]=='?';}
bool ps(int i){return c[i]=='*'||c[i]=='?';}
signed main(){
    scanf("%d %d\n%s",&n,&k,c+1);
    fu(len,2,n,1,1){
        fu(l,1,n-len+1,1,1){
            int r=l+len-1;
            if(pl(l)&&pr(r)){
                if(len-2<=k){
                    bool flg=1;
                    fu(i,l+1,r-1,1,1)if(!ps(i)){flg=0;break;}
                    w[l][r]=flg;
                }
                f[l][r]=w[l][r]=((1LL*w[l][r]+g[l+1][r-1]+h[l+1][r-1]-f[l+1][r-1])%LJC+LJC)%LJC;
                fu(i,l+1,r-1,1,1)if(pr(i))
                    f[l][r]=(f[l][r]+1LL*w[l][i]*g[i+1][r]%LJC)%LJC;
            }
            g[l][r]=h[l][r]=f[l][r];
            fu(i,l,r-1,1,(ps(i)&&i-l+1<=k)){    // * len <= k
                g[l][r]=(g[l][r]+f[i+1][r])%LJC;
            }
            fd(i,r,l+1,1,(ps(i)&&r-i+1<=k)){// * len <= k
                h[l][r]=(h[l][r]+f[l][i-1])%LJC;
            }
        }
    }
    printf("%d",f[1][n]);

    return 0;
}