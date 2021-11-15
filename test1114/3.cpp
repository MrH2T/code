#include<bits/stdc++.h>
#define int long long
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
const int MAXN = 1000050, INF = 2e18;
int n,m,q,a[MAXN],b[MAXN];
int p[MAXN],k[MAXN],kk[MAXN],id[MAXN],ans[MAXN];
struct nd{
    int k,b;
    int operator[](int x){return 1ll*k*x+b;}
}tr[MAXN<<2];
#define ls p<<1
#define rs p<<1|1
#define k(p) tr[p].k
#define b(p) tr[p].b
void build(int p,int l,int r){
    k(p)=INF;
    if(l==r)return;
    int mid=l+r>>1;
    build(ls,l,mid),build(rs,mid+1,r);
}
void modify(int p,int l,int r,nd x){
    if(k(p)==INF)return void(tr[p]=x);
    int mid=l+r>>1;
    if(x[kk[mid]]<tr[p][kk[mid]])swap(x,tr[p]);
    if(x[kk[l]]<tr[p][kk[l]])modify(ls,l,mid,x);
    if(x[kk[r]]<tr[p][kk[r]])modify(rs,mid+1,r,x);
}
int query(int p,int l,int r,int x){
    if(k(p)==INF)return INF;
    int mid=l+r>>1;
    if(kk[mid]==x)return tr[p][x];
    return min(tr[p][x],x<kk[mid]?query(ls,l,mid,x):query(rs,mid+1,r,x));
}
void solve(){
    int pt=1,sa=0,sb=0;
    build(1,1,q);
    fu(i,1,n,1,1){
        modify(1,1,q,nd{-sb,sa});
        sa+=a[i],sb+=b[i];
        while(pt<=m&&p[id[pt]]<=i)
            ans[id[pt]]+=sa-k[id[pt]]*sb
                -query(1,1,q,k[id[pt]]),pt++;
    }
}
signed main(){
    n=read(),m=read();
    fu(i,1,n,1,1)a[i]=read(),b[i]=read();
    fu(i,1,m,1,1)p[i]=read(),kk[i]=k[i]=read();
    sort(kk+1,kk+m+1),q=unique(kk+1,kk+m+1)-kk-1;
    iota(id,id+m+1,0);
    sort(id+1,id+m+1,[&](int x,int y)->bool{return p[x]<p[y];});
    
    solve();
    fu(i,1,m,1,1)ans[i]-=a[p[i]]-k[i]*b[p[i]],p[i]=n-p[i]+1;
    reverse(a+1,a+n+1),reverse(b+1,b+n+1),reverse(id+1,id+m+1);
    solve();
    fu(i,1,m,1,1)printf("%lld\n",ans[i]);
}