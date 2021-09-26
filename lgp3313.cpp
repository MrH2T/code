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

int n,q;
int w[MAXN],c[MAXN];
char op[2];
namespace CFS{
    int cnt,head[MAXN],nxt[MAXN<<1],to[MAXN<<1];
    void add(int u,int v){nxt[++cnt]=head[u],head[u]=cnt,to[cnt]=v;}
}
namespace SEG{
    inline int _max(int a,int b){return a>b?a:b;}
    struct node{
        int ls,rs;
        int sum,mx;
    }tr[MAXN*16<<1];
    #define ls(p) tr[p].ls
    #define rs(p) tr[p].rs
    #define sum(p) tr[p].sum
    #define mx(p) tr[p].mx
    int cnt,root[MAXN];
    void push_up(int p){
        sum(p)=sum(ls(p))+sum(rs(p));
        mx(p)=_max(mx(ls(p)),mx(rs(p)));
    }
    void modify(int &p,int l,int r,int x,int k){
        if(!p)p=++cnt;
        if(l==r){
            sum(p)=mx(p)=k;
            return ;
        }
        int mid=l+r>>1;
        if(x<=mid)modify(ls(p),l,mid,x,k);
        else modify(rs(p),mid+1,r,x,k);
        push_up(p);
    }
    int queryMax(int p,int l,int r,int ll,int rr){
        if(!p)return 0;
        if(ll<=l&&r<=rr)return mx(p);
        int mid=l+r>>1,res=0;
        if(ll<=mid)res=_max(res,queryMax(ls(p),l,mid,ll,rr));
        if(rr>mid)res=_max(res,queryMax(rs(p),mid+1,r,ll,rr));
        return res;
    }
    int querySum(int p,int l,int r,int ll,int rr){
        if(!p)return 0;
        if(ll<=l&&r<=rr)return sum(p);
        int mid=l+r>>1,res=0;
        if(ll<=mid)res+=querySum(ls(p),l,mid,ll,rr);
        if(rr>mid)res+=querySum(rs(p),mid+1,r,ll,rr);
        return res;
    }
}
namespace SLPF{
    
    int dfn[MAXN],dep[MAXN],fa[MAXN],son[MAXN],top[MAXN],sz[MAXN],dfncnt;
    void dfs1(int p,int f){
        dep[p]=dep[f]+1,fa[p]=f;
        sz[p]=1;
        for(int i=CFS::head[p],sn;i;i=CFS::nxt[i])if((sn=CFS::to[i])!=f){
            dfs1(sn,p);
            sz[p]+=sz[sn];
            if(sz[sn]>sz[son[p]])son[p]=sn;
        }
    }
    void dfs2(int p,int tpf){
        dfn[p]=++dfncnt;
        top[p]=tpf;
        if(!son[p])return;
        dfs2(son[p],tpf);
        for(int i=CFS::head[p],sn;i;i=CFS::nxt[i]){
            if((sn=CFS::to[i])!=fa[p]&&sn!=son[p])dfs2(sn,sn);
        }
    }
    void modifyColor(int x,int ch){
        int color=c[x],v=SEG::querySum(SEG::root[color],1,n,dfn[x],dfn[x]);
        SEG::modify(SEG::root[color],1,n,dfn[x],0);
        SEG::modify(SEG::root[ch],1,n,dfn[x],v);
        c[x]=ch;
    }
    void modifyValue(int x,int k){
        int color=c[x];
        SEG::modify(SEG::root[color],1,n,dfn[x],k);
    }
    int queryMax(int x,int y){
        int col=c[x],res=0;
        while(top[x]!=top[y]){
            if(dep[top[x]]<dep[top[y]])swap(x,y);
            res=max(res,SEG::queryMax(SEG::root[col],1,n,dfn[top[x]],dfn[x]));
            x=fa[top[x]];
        }
        if(dep[x]>dep[y])swap(x,y);
        res=max(res,SEG::queryMax(SEG::root[col],1,n,dfn[x],dfn[y]));
        return res;
    }
    int querySum(int x,int y){
        int col=c[x],res=0;
        while(top[x]!=top[y]){
            if(dep[top[x]]<dep[top[y]])swap(x,y);
            res+=SEG::querySum(SEG::root[col],1,n,dfn[top[x]],dfn[x]);
            x=fa[top[x]];
        }
        if(dep[x]>dep[y])swap(x,y);
        res+=SEG::querySum(SEG::root[col],1,n,dfn[x],dfn[y]);
        return res;
    }
}
signed main(){
    n=read(),q=read();
    fu(i,1,n,1,1)w[i]=read(),c[i]=read();
    fu(i,1,n-1,1,1){
        int u=read(),v=read();
        CFS::add(u,v),CFS::add(v,u);
    }
    SLPF::dfs1(1,0);
    SLPF::dfs2(1,1);
    fu(i,1,n,1,1){
        SLPF::modifyValue(i,w[i]);
    }

    fu(i,1,q,1,1){
        int x,y;
        scanf("%s %d %d\n",op,&x,&y);
        if(op[0]=='Q'){
            if(op[1]=='S')printf("%d\n",SLPF::querySum(x,y));
            else printf("%d\n",SLPF::queryMax(x,y));
        }else{
            if(op[1]=='C')SLPF::modifyColor(x,y);
            else SLPF::modifyValue(x,y);
        }
    }
}
