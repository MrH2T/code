#include<bits/stdc++.h>
#define rint register int
#define fu(i,a,b,d,c) for(rint i=a;i<=b&&c;i+=d)
#define fd(i,a,b,d,c) for(rint i=a;i>=b&&c;i-=d)
using namespace std;
const int MAXN = 605;
char s[MAXN];
int n,a[MAXN*MAXN];
int ha(int x,int y){return (x-1)*n+y;}
int fa[MAXN*MAXN];
int find(int x){
    return x==fa[x]?fa[x]:fa[x]=find(fa[x]);
}
signed main(){
    scanf("%d\n",&n);
    fu(i,1,n,1,1){
        scanf("%s\n",s+1);
        fu(j,1,n,1,1)a[ha(i,j)]=s[j]=='X'?1:s[j]=='O'?2:0;
    }
    fu(i,1,n,1,1)fu(j,1,n,1,1)fa[ha(i,j)]=ha(i,j);
    int p=0;
    while(1){
        
        p^=1;
    }
    
}