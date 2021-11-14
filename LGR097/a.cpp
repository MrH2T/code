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
int n,k;
int b[1050];
void dfs(int num,int lft,int sum){
    if(num>1000)return;
    if(sum>k)return;
    if(sum+lft==k){
        printf("%d\n",num);
        fu(i,1,num-1,1,1)printf("%d ",b[i]);
        printf("%d ",lft);
        exit(0);
    }
    fu(i,1,lft,1,1)if(lft%i==0){
        b[num]=i;
        dfs(num+1,lft/i,sum+i);
    }
}
signed main(){
    n=read(),k=read();
    dfs(1,n,0);
    printf("-1");
}