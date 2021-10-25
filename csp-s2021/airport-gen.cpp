#include<bits/stdc++.h>
#define rint int
#define fu(i,a,b,d,c) for(rint i=a;i<=b&&c;i+=d)
#define fd(i,a,b,d,c) for(rint i=a;i>=b&&c;i-=d)
using namespace std;
inline int read(){
    char c=0,f=1;int num=0;
    while(c<'0'||c>'9'&&c!='-')((c=getchar())=='-')&&(f=-f);
    while(c>='0'&&c<='9')num=(num<<1)+(num<<3)+(c^48),c=getchar();
    return num*f;
}
map<int,bool> bk;
mt19937 rd(time(0));
int random(int l,int r){
    return (llabs(rd())%(r-l+1))+l;
}
signed main(){
    const int N = 100000, M1 = 50000, M2 = 50000, V = 1e8;
    printf("%d %d %d\n",N,M1,M2);
    fu(i,1,M1,1,1){
        int l=random(1,V);
        while(bk[l])l=random(1,V);
        bk[l]=1;
        int r=random(1,V);
        while(bk[r])r=random(1,V);
        bk[r]=1;
        if(l>r)swap(l,r);
        printf("%d %d\n",l,r);
    }
    fu(i,1,M2,1,1){
        int l=random(1,V);
        while(bk[l])l=random(1,V);
        bk[l]=1;
        int r=random(1,V);
        while(bk[r])r=random(1,V);
        bk[r]=1;
        if(l>r)swap(l,r);
        printf("%d %d\n",l,r);
    }
}