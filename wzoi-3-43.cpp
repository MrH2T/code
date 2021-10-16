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
const int MAXN = 23;
int n,a[MAXN];
int sg[MAXN],ha[1050];
int sm;
signed main(){
    sg[0]=0;
    fu(i,1,20,1,1){
        memset(ha,0,sizeof(ha));
        fu(j,0,i-1,1,1){
            fu(k,0,j,1,1)ha[sg[j]^sg[k]]=1;
        }
        int j=0;
        while(1|(j++))if(!ha[j]){sg[i]=j;break;}
    }
    int T=read();
    while(T--){
        n=read();sm=0;
        fd(i,n-1,0,1,1)if((a[n-i-1]=read())&1)sm^=sg[i];
        if(sm==0){printf("-1 -1 -1\n0\n");continue;}
        int cnt=0;
        fu(i,1,n,1,1)if(a[i-1]){
            fu(j,i+1,n,1,1){
                fu(k,j,n,1,1)if(0==(sm^sg[n-i]^sg[n-j]^sg[n-k])){
                    if(!cnt)printf("%d %d %d\n",i-1,j-1,k-1);
                    cnt++;
                }
            }
        }
        printf("%d\n",cnt);
    }
}
