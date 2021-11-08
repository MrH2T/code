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
const int MAXN = 100050;
int n,siz;
signed cnt,head[MAXN],to[MAXN<<1],val[MAXN<<1],nxt[MAXN<<1];
void add(int u,int v,int w){
    nxt[++cnt]=head[u],head[u]=cnt,to[cnt]=v,val[cnt]=w;
}
int sum[MAXN];
namespace Seg{
    struct node{
        signed ls,rs;
        signed cnt;
        int sum;
    }tr[MAXN<<5];
    #define ls(p) tr[p].ls
    #define rs(p) tr[p].rs
    #define cnt(p) tr[p].cnt
    #define sum(p) tr[p].sum
    signed ccnt,root[MAXN];
    void push_up(int rt){
        cnt(rt)=cnt(ls(rt))+cnt(rs(rt));
        sum(rt)=sum(ls(rt))+sum(rs(rt));
    }
    void merge(signed &rt1,signed rt2){
        if(!rt1||!rt2)return void(rt1+=rt2);
        sum(rt1)+=sum(rt2),cnt(rt1)+=cnt(rt2);
        merge(ls(rt1),ls(rt2)),merge(rs(rt1),rs(rt2));
    }
    void add(signed &rt,int l,int r,int x,int k){
        if(!rt)rt=++ccnt;
        if(l==r){
            cnt(rt)++,sum(rt)+=k;
            return;
        }
        int mid=l+r>>1;
        if(x<=mid)add(ls(rt),l,mid,x,k);
        else add(rs(rt),mid+1,r,x,k);
        push_up(rt);
    }
    int query(int rt,int l,int r,int ll,int rr,int flag){
        if(ll>rr||!rt)return 0;
        if(ll<=l&&r<=rr)return !flag?cnt(rt):sum(rt);
        int mid=l+r>>1,res=0;
        if(ll<=mid)res+=query(ls(rt),l,mid,ll,rr,flag);
        if(rr>mid)res+=query(rs(rt),mid+1,r,ll,rr,flag);
        return res;
    }
}
int tmparr[MAXN],id[MAXN];
void dfs(int p,int fa){
    for(int i=head[p],sn;i;i=nxt[i])if((sn=to[i])!=fa){
        sum[sn]=sum[p]+val[i];
        dfs(sn,p);
    }
}
vector<pair<int,int> > qr[MAXN];
int ans[MAXN];
void dfs1(int p,int fa){
    Seg::add(Seg::root[p],1,siz,id[p],sum[p]);
    for(int i=head[p],sn;i;i=nxt[i])if((sn=to[i])!=fa){
        dfs1(sn,p);
        Seg::merge(Seg::root[p],Seg::root[sn]);
    }
    for(pair<int,int> qq:qr[p]){
        int kk=qq.second+sum[p];
        int pos=lower_bound(tmparr+1,tmparr+siz+1,kk)-tmparr;
        ans[qq.first]=Seg::query(Seg::root[p],1,siz,pos,siz,1)-sum[p]*Seg::query(Seg::root[p],1,siz,pos,siz,0);
    }
}
signed main(){
//    freopen("dat.in","r",stdin);
//    freopen("me.out","w",stdout);
    n=read();
//    memset(Seg::tr,0,sizeof(Seg::tr));
    fu(i,2,n,1,1){
        int fa=read(),w=read();
        add(i,fa,w),add(fa,i,w);
    }
    dfs(1,0);
    memcpy(tmparr,sum,sizeof(sum)),sort(tmparr+1,tmparr+n+1);
    siz=unique(tmparr+1,tmparr+n+1)-tmparr-1;
	fu(i,1,n,1,1)id[i]=lower_bound(tmparr+1,tmparr+siz+1,sum[i])-tmparr;
    int q=read();
    fu(i,1,q,1,1){
        int u=read(),k=read();
        qr[u].push_back(make_pair(i,k));
    }
    dfs1(1,0);
    fu(i,1,q,1,1)printf("%lld\n",ans[i]);
}
