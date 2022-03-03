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
const int MAXN = 100050, V = 20;
int n,m,a[MAXN];
struct segtree{
    struct nd{int len,sum;bool tag;}tr[MAXN<<2];
    #define ls p<<1
    #define rs p<<1|1
    #define len(p) tr[p].len
    #define sum(p) tr[p].sum
    #define tag(p) tr[p].tag
    void push_up(int p){sum(p)=sum(ls)+sum(rs);}
    void push_down(int p){
        if(tag(p)){
            tag(ls)^=1,tag(rs)^=1;
            sum(ls)=len(ls)-sum(ls),sum(rs)=len(rs)-sum(rs);
            tag(p)=0;
        }
    }
    void build(int p,int l,int r,int k){
        len(p)=r-l+1;sum(p)=0;
        if(l==r){
            sum(p)=(a[l]>>k)&1;
            return;
        }
        int mid=l+r>>1;
        build(ls,l,mid,k),build(rs,mid+1,r,k);
        push_up(p);
    }
    void modify(int p,int l,int r,int ll,int rr){
        if(ll<=l&&r<=rr){
            tag(p)^=1,sum(p)=len(p)-sum(p);
            return;
        }
        push_down(p);
        int mid=l+r>>1;
        if(ll<=mid)modify(ls,l,mid,ll,rr);
        if(rr>mid)modify(rs,mid+1,r,ll,rr);
        push_up(p);
    }
    int query(int p,int l,int r,int ll,int rr){
        if(ll<=l&&r<=rr)return sum(p);
        push_down(p);
        int mid=l+r>>1,res=0;
        if(ll<=mid)res+=query(ls,l,mid,ll,rr);
        if(rr>mid)res+=query(rs,mid+1,r,ll,rr);
        return res;
    }
}T[25];
void prt(){fu(i,1,n,1,1){
        fd(j,V,0,1,1)printf("%d",T[j].query(1,1,n,i,i));putchar('\n');
    }}
signed main(){
    n=read();fu(i,1,n,1,1)a[i]=read();
    fu(i,0,V,1,1)T[i].build(1,1,n,i);
    m=read();
    fu(i,1,m,1,1){
        int op=read();
        if(op==1){
            int l=read(),r=read();
            long long ans=0;
            fu(j,0,V,1,1)ans+=1ll*T[j].query(1,1,n,l,r)<<j;
            printf("%lld\n",ans);
        }else{
            int l=read(),r=read(),x=read();
            fu(j,0,V,1,1)if((x>>j)&1)T[j].modify(1,1,n,l,r);
        }
    }
}