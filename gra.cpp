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
const int MAXN = 1000050;
int m,n;
int pos[MAXN],bla[MAXN],lx[MAXN];
signed main(){
    m=read()-2,n=read();
    fu(i,1,n,1,1)pos[i]=read();
    fd(i,n,1,1,1){
        bla[i]=(m-pos[i])-(n-i);
        lx[i]=(bla[i]==bla[i+1])?lx[i+1]+1:1;
    }
    fu(i,1,n,1,1)lx[i]=(bla[i]==bla[i-1])?lx[i-1]:lx[i];
//    fu(i,1,n,1,1)printf("%d ",bla[i]);
    int res=0;
    fu(i,1,n,1,1){
        if((bla[i]&1)&&bla[i]!=bla[i-1])res^=lx[i];
    }
    int ans=0;
    fu(i,1,n,1,1){
        if((bla[i])&&((res^lx[i])==0))ans++;
    }
    printf("%d",ans);
}
