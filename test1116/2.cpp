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
const int MAXN = 400, LJC = 998244353;
inline int inv(int x){
    int res=1,p=LJC-2;
    for(;p;p>>=1,x=1ll*x*x%LJC)(p&1)&&(res=1ll*res*x%LJC);
    return res;
}
int n,m;
int eq[MAXN][MAXN];
int tmp[MAXN],cnt;
void gause(){
    fu(i,1,cnt,1,1){
        fu(j,1,3*n,1,1)if(eq[i][j]){
            if(!tmp[j])break;
            int rate=1ll*tmp[j]*inv(eq[i][j])%LJC;
            fu(k,1,3*n+1,1,1)tmp[k]=(1ll*tmp[k]+LJC-1ll*rate*eq[i][k]%LJC)%LJC;
            break;
        }
    }
}
signed main(){
    n=read(),m=read();
    while(m--){
        int op=read();
        memset(tmp,0,sizeof(tmp));
        fu(i,1,n,1,1){int x=read(),v=read();tmp[i+n*v]+=x;}
        fu(i,1,n,1,1){int x=read(),v=read();tmp[i+n*v]+=LJC-x;}
        fu(i,1,3*n,1,1)tmp[i]%=LJC;
        if(op==1){
            tmp[3*n+1]=read();
            gause();
            bool flag=0;
            fu(i,1,3*n,1,1)if(tmp[i]){flag=1;break;}
            if(!flag&&tmp[3*n+1]){printf("There must be some thing wrong!\n");continue;}
            else if(flag)memcpy(eq[++cnt],tmp,sizeof(tmp));
        }
        else{
            gause();
            bool flag=0;
            fu(i,1,3*n,1,1)if(tmp[i]){flag=1;break;}
            if(flag){printf("No answer.\n");continue;}
            else printf("%d\n",LJC-tmp[3*n+1]);
        }
    }
}