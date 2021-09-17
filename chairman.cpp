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
const int MAXN = 200050;
namespace Chairman{
    struct node{
        int ls,rs,sum;
    }tr[MAXN*16<<1];
    #define ls(p) tr[p].ls
    #define rs(p) tr[p].rs
    #define sum(p) tr[p].sum
    int cnt;
    void modify(int &rt,int p,int l,int r,int x){
        rt=++cnt;
        ls(rt)=ls(p),rs(rt)=rs(p),sum(rt)=sum(p)+1;
        if(l==r)return;
        int mid=l+r>>1;
        if(x<=mid)modify(ls(rt),ls(p),l,mid,x);
        else modify(rs(rt),rs(p),mid+1,r,x);
    }
    int query(int rt1,int rt2,int l,int r,int k){
//    	printf("rt1:%d rt2:%d l:%d r:%d k:%d\n",rt1,rt2,l,r,k);
//    	printf("sum(ls(rt1)):%d sum(ls(rt2)):%d\nsum(rs(rt1)):%d sum(rs(rt2)):%d\n",
//			sum(ls(rt1)),sum(ls(rt2)),sum(rs(rt1)),sum(rs(rt2)));
        if(l==r)return l;
        int mid=l+r>>1;
        if(sum(ls(rt1))-sum(ls(rt2))>=k)
            return query(ls(rt1),ls(rt2),l,mid,k);
        else 
            return query(rs(rt1),rs(rt2),mid+1,r,k-(sum(ls(rt1))-sum(ls(rt2))));
    }
}
using namespace Chairman;
struct dt{int v,id,lv;}a[MAXN];
bool cmp(dt x,dt y){return x.v<y.v;}
bool cmp2(dt x,dt y){return x.id<y.id;}
int n,m,root[MAXN],lsh[MAXN];

signed main(){
//	freopen("P3834_4.in","r",stdin);
//	freopen("me.out","w",stdout);
    n=read(),m=read();
    fu(i,1,n,1,1)a[i]=(dt){read(),i};
    sort(a+1,a+n+1,cmp);
    a[0].v=-1e9-10;
    int sbabs=0;
    fu(i,1,n,1,1){
        sbabs+=(a[i].v!=a[i-1].v);
        a[i].lv=sbabs;
        lsh[sbabs]=a[i].v;
    }
    sort(a+1,a+n+1,cmp2);
    fu(i,1,n,1,1)modify(root[i],root[i-1],1,n,a[i].lv);
    fu(i,1,m,1,1){
        int l=read(),r=read(),k=read();
        int kth=query(root[r],root[l-1],1,n,k);
        printf("%d\n",lsh[kth]);
    }
}
