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
const int MAXN = 1e6+50;
struct ele{int v,x;ele(){v=x=0;}}a[MAXN],b[MAXN],d[MAXN];
pair<int,int> c[MAXN];
int tmp[MAXN],tmp2[MAXN],ccnt,cc;
int lb(int x){ //lowerbound
    int l=1,r=ccnt;
    while(l<r){
        int mid=l+r>>1;
        if(tmp[mid]==x)return mid;
        if(tmp[mid]>x)r=mid;
        else l=mid+1;
    }
    return l;
}
int lb2(int x){ //lowerbound
    int l=1,r=cc;
    while(l<r){
        int mid=l+r>>1;
        if(tmp2[mid]==x)return mid;
        if(tmp2[mid]>x)r=mid;
        else l=mid+1;
    }
    return l;
}
namespace seg{
    inline int Min(int a,int b){return a<b?a:b;}
    struct nd{ 
        int l,r;
        int mn,tag;
    }tr[MAXN<<2];
    #define ls(p) p<<1
    #define rs(p) p<<1|1
    #define mn(p) tr[p].mn
    #define tag(p) tr[p].tag
    inline void push_up(int p){
        mn(p)=Min(mn(ls(p)),mn(rs(p)));
    }
    inline void push_down(int p){
        if(tag(p)){
            tag(ls(p))+=tag(p),tag(rs(p))+=tag(p);
            mn(ls(p))+=tag(p),mn(rs(p))+=tag(p);
            tag(p)=0;
        }
    }
    inline void build(int p,int l,int r){
        mn(p)=tag(p)=0;
        if(l==r)return;
        int mid=l+r>>1;
        build(ls(p),l,mid);
        build(rs(p),mid+1,r);
    }
    inline void modify(int p,int l,int r,int ll,int rr,int k){
        if(ll<=l&&r<=rr){
            tag(p)+=k,mn(p)+=k;
            return;
        }
        push_down(p);
        int mid=l+r>>1;
        if(ll<=mid)modify(ls(p),l,mid,ll,rr,k);
        if(rr>mid)modify(rs(p),mid+1,r,ll,rr,k);
        push_up(p);
    }
}
int T,n,m;
namespace bit{
    int tr[MAXN];
    inline void add(int x){
        for(;x<=n;x+=x&-x)tr[x]++;
    }
    inline int query(int x){
        int sum=0;
        for(;x;x-=x&-x)sum+=tr[x];
        return sum;
    }
}
signed main(){
    #ifndef ONLINE_JUDGE
    freopen("dat.in","r",stdin);
    freopen("dat.out","w",stdout);
    #endif
    T=read();
    while(T--){
        n=read(),m=read();
        ccnt=0;
        fu(i,1,n,1,1)d[i].v=a[i].v=read(),tmp[++ccnt]=a[i].v,tmp2[i]=a[i].v;
        fu(i,1,m,1,1)b[i].v=read(),tmp[++ccnt]=b[i].v;
        //lsh
        sort(tmp+1,tmp+ccnt+1);
        ccnt=unique(tmp+1,tmp+ccnt+1)-tmp-1;
        fu(i,1,n,1,1)a[i].x=lb(a[i].v);
        fu(i,1,m,1,1)b[i].x=lb(b[i].v);
        sort(tmp2+1,tmp2+n+1);
        cc=unique(tmp2+1,tmp2+n+1)-tmp2-1;
        fu(i,1,n,1,1)d[i].x=lb2(d[i].v);
 
        sort(b+1,b+m+1,[](ele a,ele b)->bool{return a.x<b.x;});
        fu(i,1,n,1,1)c[i]=make_pair(a[i].x,i);
        sort(c+1,c+n+1);
 
        long long ans=0;
        // memset(bit::tr,0,sizeof(bit::tr));
        fu(i,1,n,1,1)bit::tr[i]=0;
        fd(i,n,1,1,1){
            ans+=bit::query(d[i].x-1);
            bit::add(d[i].x);
        }
        
        int ptr=1;
        seg::build(1,0,n);
        fu(i,1,n,1,1){
            seg::modify(1,0,n,i,n,(a[i].x==b[1].x?0:a[i].x<b[1].x?-1:1));
        }
        while(ptr<=n&&b[1].x>c[ptr].first)ptr++;
        int tmpptr=ptr;
        ans+=tmpptr-1+seg::mn(1);
 
        fu(i,2,m,1,1){
            if(b[i].x==b[i-1].x){
                ans+=tmpptr-1+seg::mn(1);
                continue;
            }
            while(ptr<=n&&c[ptr].first==b[i-1].x)
                seg::modify(1,0,n,c[ptr].second,n,-1),ptr++;
            while(ptr<=n&&c[ptr].first<b[i].x)
                seg::modify(1,0,n,c[ptr].second,n,-2),ptr++;
            tmpptr=ptr;
            while(ptr<=n&&c[ptr].first==b[i].x)
                seg::modify(1,0,n,c[ptr].second,n,-1),ptr++;
            ptr=tmpptr;
            ans+=tmpptr-1+seg::mn(1);
        }
        printf("%lld\n",ans);
    }
}