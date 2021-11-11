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
typedef long long ll;
const int MAXN = 100050, MAXK = 20;
int n,q;
int cnt,head[MAXN],to[MAXN<<1],nxt[MAXN<<1],val[MAXN<<1];
void add(int u,int v,int w){nxt[++cnt]=head[u],head[u]=cnt,to[cnt]=v,val[cnt]=w;}
int dep[MAXN],fa[MAXN][21];
ll dis[MAXN],mxdis[MAXN][3],up[MAXN][21],down[MAXN][21];
inline void cmax(int p,ll x){
    if(x>mxdis[p][0])mxdis[p][2]=mxdis[p][1],mxdis[p][1]=mxdis[p][0],mxdis[p][0]=x;
    else if(x>mxdis[p][1])mxdis[p][2]=mxdis[p][1],mxdis[p][1]=x;
    else if(x>mxdis[p][2])mxdis[p][2]=x;
}
void dfs(int p,int fat){
    fa[p][0]=fat,dep[p]=dep[fat]+1;
    fu(i,1,MAXK,1,1){
        fa[p][i]=fa[fa[p][i-1]][i-1];
    }
    for(int i=head[p],t;i;i=nxt[i])if((t=to[i])!=fat){
        dis[t]=dis[p]+val[i];
        dfs(t,p);
        cmax(p,mxdis[t][0]+val[i]);
    }
    for(int i=head[p],t;i;i=nxt[i])if((t=to[i])!=fat){
        if(mxdis[t][0]+val[i]==mxdis[p][0]){
            up[t][0]=mxdis[p][1]+val[i];
            down[t][0]=mxdis[p][1];
        }else{
            up[t][0]=mxdis[p][0]+val[i];
            down[t][0]=mxdis[p][0];
        }
    }
}
inline int lca(int u,int v){
    (dep[u]<dep[v])&&(swap(u,v),1);
    fd(i,MAXK,0,1,1)(dep[fa[u][i]]>=dep[v])&&(u=fa[u][i]);
    if(u==v)return u;
    fd(i,MAXK,0,1,1)(fa[u][i]!=fa[v][i])&&(u=fa[u][i],v=fa[v][i]);
    return fa[u][0];
}
inline int kth(int u,int k){
    fu(i,0,MAXK,1,1)if(k>>i&1)u=fa[u][i];
    return u;
}
inline ll getup(int u,int v){
    if(dep[u]<dep[v])swap(u,v);
    ll res=0;int u0=u;
    fd(i,MAXK,0,1,1){
        if(dep[fa[u][i]]>=dep[v]){
            res=max(res,dis[u0]-dis[u]+up[u][i]);
            u=fa[u][i];
        }
    }
    return res;
}
inline ll getdown(int u,int v){
    if(dep[u]<dep[v])swap(u,v);
    ll res=0;
    fd(i,MAXK,0,1,1){
        if(dep[fa[u][i]]>=dep[v]){
            res=max(res,dis[fa[u][i]]-dis[v]+down[u][i]);
            u=fa[u][i];
        }
    }
    return res;
}
inline void mult(){
    fu(k,1,MAXK,1,1){
        fu(p,1,n,1,1){
            fa[p][k]=fa[fa[p][k-1]][k-1];
            up[p][k]=max(up[p][k-1],up[fa[p][k-1]][k-1]+dis[p]-dis[fa[p][k-1]]);
            down[p][k]=max(down[p][k-1]+dis[fa[p][k-1]]-dis[fa[p][k]],down[fa[p][k-1]][k-1]);
        }
    }
}
signed main(){
    n=read(),q=read();
    fu(i,1,n-1,1,1){
        int u=read(),v=read(),w=read();
        add(u,v,w),add(v,u,w);
    }
    dfs(1,0);
    mult();
    while(q--){
        int u=read(),v=read();
        if(dis[u]<dis[v])swap(u,v);//u is the deeper
        int midp=u,lc=lca(u,v);
        ll disuv=dis[u]+dis[v]-2ll*dis[lc];
        fd(i,MAXK,0,1,1)if((dis[u]-dis[fa[midp][i]])*2<disuv)midp=fa[midp][i];
        ll ans=0;
        if(lc==v){
            ans=max(ans,mxdis[u][0]);
            ans=max(ans,getup(v,1));
            ans=max(ans,getup(u,midp));
            ans=max(ans,getdown(v,midp));
        }
        else{
            ans=max(ans,mxdis[u][0]);
            ans=max(ans,mxdis[v][0]);
            ans=max(ans,getup(lc,1)+dis[v]-dis[lc]);
            ans=max(ans,getup(midp,u));

            int vtlc=kth(v,dep[v]-dep[lc]-1);
            int utlc=kth(u,dep[u]-dep[lc]-1);
            if(midp!=utlc)ans=max(ans,getdown(midp,utlc)+dis[v]+dis[utlc]-2*dis[lc]);
            if(v!=vtlc)ans=max(ans,getup(v,vtlc));
            ll mx1=mxdis[utlc][0]+dis[utlc]-dis[lc],mx2=mxdis[vtlc][0]+dis[vtlc]-dis[lc];
            if(mx1<mx2)swap(mx1,mx2);
            if(mxdis[lc][0]==mx1&&mxdis[lc][1]==mx2)ans=max(ans,mxdis[lc][2]+dis[v]-dis[lc]);
            else if(mxdis[lc][0]==mx1)ans=max(ans,mxdis[lc][1]+dis[v]-dis[lc]);
            else ans=max(ans,mxdis[lc][0]+dis[v]-dis[lc]);
        }
        printf("%lld\n",ans);
    }
}