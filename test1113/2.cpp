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
const int MAXC = 300050, MAXN  = 300050;
struct dat{
    int p,l,r,k;
}op[MAXC<<1];
int n,m,c,k,q,cnt;
struct seg{
    int sum[12],sh;
    seg(){memset(sum,0,sizeof(sum)),sh=0;}
}tr[MAXN<<2];
int tag[MAXN<<2];
#define ls p<<1
#define rs p<<1|1
void build(int p,int l,int r){
    tr[p].sh=0,tr[p].sum[0]=r-l+1;
    if(l==r)return;
    int mid=l+r>>1;
    build(ls,l,mid),build(rs,mid+1,r);
}
void modify(int p,int l,int r,int ll,int rr,int x){
    if(ll<=l&&r<=rr)return ({tag[p]+=x,tr[p].sh+=x;void();});
    int mid=l+r>>1;
    if(ll<=mid)modify(ls,l,mid,ll,rr,x);
    if(rr>mid)modify(rs,mid+1,r,ll,rr,x);
    if(tr[ls].sh<tr[rs].sh){
        tr[p]=tr[ls];
        int del=tr[rs].sh-tr[ls].sh;
        fu(i,0,k-del-1,1,1)tr[p].sum[i+del]+=tr[rs].sum[i];
    }
    else{
        tr[p]=tr[rs];
        int del=tr[ls].sh-tr[rs].sh;
        fu(i,0,k-del-1,1,1)tr[p].sum[i+del]+=tr[ls].sum[i];
    }
    tr[p].sh+=tag[p];
}
int query(){
    return ({int res=0;fu(i,0,k-tr[1].sh-1,1,1)res+=tr[1].sum[i];res;});
}
long long num[MAXN],s[MAXN],ss[MAXN];
int cntnum[MAXN];
signed main(){
    n=read(),m=read(),c=read(),k=read(),q=read();
    fu(i,1,c,1,1){
        int x=read(),y=read(),xx=read(),yy=read();
        op[++cnt]=(dat){x,y,yy,1};
        op[++cnt]=(dat){xx+1,y,yy,-1};
    }
    sort(op+1,op+cnt+1,[](dat a,dat b){return a.p<b.p;});
    build(1,1,m);
    int ptr=1;
    fu(i,1,n,1,1){
        while(ptr<=cnt&&op[ptr].p<=i)modify(1,1,m,op[ptr].l,op[ptr].r,op[ptr].k),ptr++;
        num[i]=query();
        num[i]=min(num[i],m-num[i]);
    }
    // fu(i,1,n,1,1)printf("%d ",num[i]);putchar('\n');
    sort(num+1,num+n+1,[](int x,int y){return x>y;});
    fu(i,1,n,1,1){
        s[i]=s[i-1]+num[i],ss[i]+=ss[i-1]+num[i]*num[i];
        cntnum[num[i]]++;
    }
    fd(i,m,1,1,1)cntnum[i]+=cntnum[i+1];
    while(q--){
        int x=read(),y=read();
        int ch=y>>1;
        if(num[x]>=ch)printf("%lld\n",1ll*x*ch*(y-ch));
        else{
            printf("%lld\n",1ll*cntnum[ch]*ch*(y-ch)+1ll*y*(s[x]-s[cntnum[ch]])-ss[x]+ss[cntnum[ch]]);
        }
    }
}