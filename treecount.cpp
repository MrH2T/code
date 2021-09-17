#include <bits/stdc++.h>
#define int long long
#define rint register int
#define fu(i, a, b, d, c) for (rint i = a; i <= (b) && c; i += d)
#define fd(i, a, b, d, c) for (rint i = a; i >= (b) && c; i -= d)
#define fl(i,h) for(rint i=head[h];i;i=nxt[i])
using namespace std;
inline int read()
{
    char c = 0, f = 1;
    int num = 0;
    while (c < '0' || c > '9' && c != '-')
        ((c = getchar()) == '-') && (f = -f);
    while (c >= '0' && c <= '9')
        num = (num << 1) + (num << 3) + (c ^ 48), c = getchar();
    return num * f;
}
const int MAXN = 30050;
int a[MAXN],cntE;
int n,m;
namespace CFSTAR{
    int nxt[MAXN<<1],head[MAXN],to[MAXN<<1];
    void add(int u,int v){nxt[++cntE]=head[u],head[u]=cntE,to[cntE]=v;}
}
using namespace CFSTAR;
namespace SegmentTree{
    int INITIAL_ARRAY[MAXN];
    struct SegTree{int l,r,sum,mx,tag;}tr[MAXN<<2];
    #define l(p) tr[p].l
    #define r(p) tr[p].r
    #define sum(p) tr[p].sum
    #define tag(p) tr[p].tag
    #define mx(p) tr[p].mx
    #define ls p<<1
    #define rs p<<1|1
    void setInitialArray(int a[MAXN]){
        memcpy(INITIAL_ARRAY,a,sizeof(INITIAL_ARRAY));
    }
    void push_up(int p){sum(p)=sum(ls)+sum(rs);mx(p)=max(mx(ls),mx(rs));}
    void push_down(int p){
        if(tag(p)){
            tag(ls)=tag(rs)=tag(p);
            sum(ls)=(r(ls)-l(ls)+1)*tag(p);
            sum(rs)=(r(rs)-l(rs)+1)*tag(p);
            mx(ls)=mx(rs)=tag(p);
            tag(p)=0;
        }
    }
    void build(int p,int l,int r){
        l(p)=l,r(p)=r;
        if(l==r)return void(mx(p)=sum(p)=INITIAL_ARRAY[l]);
        int mid=l+r>>1;
        build(ls,l,mid),build(rs,mid+1,r);
        push_up(p);
    }
    void modify(int p,int l,int r,int k){
        if(l<=l(p)&&r(p)<=r){
            tag(p)=k;
            sum(p)=(r(p)-l(p)+1)*k;
            mx(p)=k;
            return;
        }
        push_down(p);
        int mid=l(p)+r(p)>>1;
        if(l<=mid)modify(ls,l,r,k);
        if(r>mid)modify(rs,l,r,k);
        push_up(p);
    }
    int querySum(int p,int l,int r){
        if(l<=l(p)&&r(p)<=r)return sum(p);
        push_down(p);
        int res=0,mid=l(p)+r(p)>>1;
        if(l<=mid)res+=querySum(ls,l,r);
        if(r>mid)res+=querySum(rs,l,r);
        return res;
    }
    int queryMax(int p,int l,int r){
    	if(l<=l(p)&&r(p)<=r)return mx(p);
        push_down(p);
        int res=-1e9,mid=l(p)+r(p)>>1;
        if(l<=mid)res=max(res,queryMax(ls,l,r));
        if(r>mid)res=max(res,queryMax(rs,l,r));
        return res;
	}
}
namespace SLPF{
    int fa[MAXN],dep[MAXN],sz[MAXN],son[MAXN];
    int id[MAXN],top[MAXN],cntN,val[MAXN];
    void dfs1(int p,int fat,int dp){
        dep[p]=dp,fa[p]=fat,sz[p]=1;
        int mxson=-1;
        fl(i,p)if(to[i]!=fat){
            int sn=to[i];
            dfs1(sn,p,dp+1);
            sz[p]+=sz[sn];
            if(sz[sn]>mxson)mxson=sz[sn],son[p]=sn;
        }
    }
    void dfs2(int p,int tfa){
        id[p]=++cntN;
        val[cntN]=a[p];
        top[p]=tfa;
        if(!son[p])return;
        dfs2(son[p],tfa);
        fl(i,p)if(to[i]!=fa[p]&&to[i]!=son[p]){
            dfs2(to[i],to[i]);
        }
    }
    int queryChainSum(int x,int y){
        int ans=0;
        while(top[x]!=top[y]){
            if(dep[top[x]]<dep[top[y]])swap(x,y);
            ans+=SegmentTree::querySum(1,id[top[x]],id[x]);
            x=fa[top[x]];
        }
        if(dep[x]>dep[y])swap(x,y);
        ans+=SegmentTree::querySum(1,id[x],id[y]);
        return ans;
    }
    int queryChainMax(int x, int y){
        int ans=-1e9;
        while(top[x]!=top[y]){
            if(dep[top[x]]<dep[top[y]])swap(x,y);
            ans=max(ans,SegmentTree::queryMax(1,id[top[x]],id[x]));
            x=fa[top[x]];
        }
        if(dep[x]>dep[y])swap(x,y);
        ans=max(ans,SegmentTree::queryMax(1,id[x],id[y]));
        return ans;
    }
    void modifyChain(int x,int y,int k){
        while(top[x]!=top[y]){
            if(dep[top[x]]<dep[top[y]])swap(x,y);
            SegmentTree::modify(1,id[top[x]],id[x],k);
            x=fa[top[x]];
        }
        if(dep[x]>dep[y])swap(x,y);
        SegmentTree::modify(1,id[x],id[y],k);
    }
}
char s[10];
signed main(){
    n=read();
    fu(i,1,n-1,1,1){
        int u=read(),v=read();
        add(u,v),add(v,u);
    }
    fu(i,1,n,1,1)a[i]=read();
	scanf("%lld\n",&m);
    SLPF::dfs1(1,0,1);
    SLPF::dfs2(1,1);
    SegmentTree::setInitialArray(SLPF::val);
    SegmentTree::build(1,1,n);
    fu(i,1,m,1,1){
		int x,y;scanf("%s %lld %lld\n",s,&x,&y);
        if(s[1]=='H'){SLPF::modifyChain(x,x,y);}
        if(s[1]=='M'){printf("%lld\n",SLPF::queryChainMax(x,y));}
        if(s[1]=='S'){printf("%lld\n",SLPF::queryChainSum(x,y));}
    }
}
