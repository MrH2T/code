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
const int MAXN = 100050;
struct bint{
    int a[100];
    bint(){memset(a,0,sizeof(a));}
    bint (int b){memset(a,0,sizeof(a));while(b)a[++a[0]]=b%10,b/=10;}
    inline int& operator[](const int id) {return a[id];}
    inline bool operator<(bint b){
        if(a[0]<b[0])return 1;
        if(a[0]>b[0])return 0;
        fd(i,a[0],1,1,1)
            if(a[i]!=b[i])return a[i]<b[i];
        return 0;
    }

    inline bint operator=(int b){
        a[0]=0;
        while(b)a[++a[0]]=b%10,b/=10;
        return *this;
    }
    inline bool operator==(bint b){
        if(a[0]!=b[0])return 0;
        fu(i,1,a[0],1,1)if(a[i]!=b[i])return 0;
        return 1;
    }
    inline bool operator<=(bint b){
        return (*this<b)||(*this==b);
    }
    inline bool operator!=(bint b){return !(*this==b);}
    inline bint operator+(bint b){
        bint c;c[0]=max(a[0],b[0]);
        fu(i,1,c[0],1,1)c[i]+=a[i]+b[i],c[i+1]+=c[i]/10,c[i]%=10;
        c[0]++;
        while(c[c[0]]>9)c[c[0]+1]+=c[c[0]]/10,c[c[0]++]%=10;
        while(!c[c[0]])c[0]--;
        return c;
    }
    inline bint operator+(int b){return *this+bint(b);}
    inline bint operator-(bint b){
        bint c;c[0]=max(a[0],b[0]);
        memcpy(c.a,a,sizeof(a));
        fu(i,1,c[0],1,1){
            while(c[i]<b[i])c[i]+=10,c[i+1]--;
            c[i]-=b[i];
        }
        while(c[0]&&!c[c[0]])c[0]--;
        return c;
    }
    inline bint read(){
        char c=0;
        while(c<'0'||c>'9')c=getchar();
        while(c>='0'&&c<='9')a[++a[0]]=c^48,c=getchar();
        reverse(a+1,a+a[0]+1);
        return *this;
    }
    inline void write(){
        fd(i,a[0],1,1,1)putchar(a[i]^48);
    }
};
int n;
struct tui{bint l,r;}a[MAXN],b[MAXN];
bool cmp(tui x,tui y){return x.l!=y.l?x.l<y.l:x.r<y.r;}
int bcnt;
signed main(){
    n=read();
    fu(i,1,n,1,1)a[i].l=read(),a[i].r=read();
    sort(a+1,a+n+1,[](tui x,tui y)->bool{return x.l!=y.l?x.l<y.l:x.r<y.r;});
    b[bcnt=1]=a[1];
    fu(i,2,n,1,1){
        if(a[i].r<=b[bcnt].r)continue;
        else b[++bcnt]=a[i];
    }
    bint ans=b[1].r-b[1].l+1;
    fu(i,2,bcnt,1,1){
        if(b[i].l<=b[i-1].r)ans=ans+b[i].r-b[i-1].r;
        else ans=ans+b[i].r-b[i].l+1;

    }
    ans.write();return 0;
}