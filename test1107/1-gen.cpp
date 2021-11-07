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
int random(int l,int r){
    return (rand()%(r-l+1))+l;
}
typedef unsigned long long ull;
map<ull,bool> bk; 
signed main(){
    srand(time(0));
    int n=10,m=20;
    printf("%d %d\n",n,m);
    fu(i,2,n,1,1){
        int u=random(1,i-1);
        printf("%d %d\n",i,u);
        bk[1ull*i*u]=1;
    }
    fu(i,1,m-n+1,1,1){
        int u=random(1,n),v=random(1,n);
        while(u==v||bk[1ull*u*v])u=random(1,n),v=random(1,n);
        printf("%d %d\n",u,v);
        bk[1ull*u*v]=1;
    }
    
}