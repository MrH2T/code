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
const int MAXN = 1e6+50;
int n,m,p;
int key[MAXN];
int lb[MAXN],rb[MAXN],bel[MAXN];
bool ok(int l,int r,int x){
    if(l>r)return false;
    return !x||l<=x&&x<=r;
}
signed main(){
    memset(bel,0x3f,sizeof(bel));
    n=read(),m=read(),p=read();
    fu(i,1,m,1,1){
        int x=read(),y=read();
        key[x]=y;
    }


    
    // fu(i,1,n,1,1)printf("%d %d\n",lb[i],rb[i]);
    fu(i,1,p,1,1){
        int s=read(),t=read();
        if(ok(lb[s],rb[s],t))printf("YES\n");
        else printf("NO\n");
    }
}