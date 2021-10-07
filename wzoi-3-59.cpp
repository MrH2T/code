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
const int MAXN = 100050, MAXB = 1000;
int n,q,a[MAXN],blk;
int sum[MAXB][MAXB];
signed main(){
    n=read(),q=read();
    fu(i,1,n,1,1){
        a[i]=read();
    }
    blk=sqrt(n);
    fu(i,1,n,1,1){
        fu(j,1,blk,1,1){
            sum[j][i%j]+=a[i];
        }
    }
    fu(i,1,q,1,1){
        int op=read(),x=read(),y=read();
        if(op==1){//query 
            if(x<=blk){
                printf("%d\n",sum[x][y]);
            }else{
                int res=0;
                fu(j,y,n,x,1)res+=a[j];
                printf("%d\n",res);
            }
        }else{  //ask
            fu(j,1,blk,1,1){
                sum[j][x%j]+=y-a[x];
            }
            a[x]=y;
        }
    }
}