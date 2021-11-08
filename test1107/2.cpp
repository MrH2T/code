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
const int MAXN = 200050, MAXK = 33;
struct praa{
    int a,b;
}p[MAXN];
int n,t;
int f[2][MAXK+1],id=0;
signed main(){
    n=read(),t=read();
    fu(i,1,n,1,1)p[i].a=read(),p[i].b=read();
    sort(p+1,p+n+1,[](praa x,praa y)->bool{
            long long u=1ll*(x.b+1)*y.a,v=1ll*(y.b+1)*x.a;
            return u==v?x.b<y.b:u<v;
        });
    int nz=0;
    for(nz=1;nz<=n;nz++)if(!p[nz].a)break;
    nz--;
    memset(f,0x3f,sizeof(f));
    f[id][0]=0;
    fu(i,1,nz,1,1){
        memcpy(f[id^1],f[id],sizeof(f[id]));
        fu(j,1,MAXK,1,1){
            if(f[id][j-1]<t){
                long long tt=1ll+1ll*p[i].a*(1ll+f[id][j-1])+p[i].b;
                if(tt+f[id][j-1]<=t){
                    f[id^1][j]=min(f[id^1][j],(int)tt+f[id][j-1]);
                }
            }
        }
        id^=1;
    }
    int ans=0;
    fu(j,0,MAXK,1,1){
        if(f[id][j]<=t){
            int now=j,tim=f[id][j];
            fu(i,nz+1,n,1,1){
                if(tim+1+p[i].b>t)break;
                tim+=1+p[i].b,now++;
            }
            ans=max(ans,now);
        }
    }
    printf("%d",ans);
}