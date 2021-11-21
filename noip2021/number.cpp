// 0.4s in O2
//if this code get 0, i'll fk ccf apart.

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
const int MAXN = 1e7+5;
// 1e7+1 is available
bitset<MAXN> ccf;
int nxt[MAXN],sb[MAXN];
int T;
void init(){
    fu(i,1,10000000,1,1){
        int x=i;
        while(x){if(x%10==7){sb[++sb[0]]=i;break;}x/=10;}
    }
    fu(i,1,sb[0],1,1){
        if(ccf[sb[i]])continue;
        fu(j,sb[i],10000000,sb[i],1){
            ccf[j]=1;
        }
    }
    int lst=10000001;
    fd(i,10000000,1,1,1){
        if(ccf[i])nxt[i]=lst;
        else nxt[i]=lst,lst=i;
    }
}
signed main(){
    // time_t st=clock();
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    init();
    T=read();
    while(T--){
        int n=read();
        if(ccf[n])printf("-1\n");
        else printf("%d\n",nxt[n]);
    }
    // fprintf(stderr,"%.3lfs\n",1.0*(clock()-st)/CLOCKS_PER_SEC);
    return 0;
}