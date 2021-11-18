#include <bits/stdc++.h>
#define int long long
#define rint register int
#define fu(i, a, b, d, c) for (rint i = a; i <= (b) && c; i += d)
#define fd(i, a, b, d, c) for (rint i = a; i >= (b) && c; i -= d)
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
const int MAXN = 1e6+50;
int n,cnt,ans;
int nxt[MAXN<<1],head[MAXN],to[MAXN<<1],val[MAXN<<1];
void add(int u,int v,int w){
    nxt[++cnt]=head[u],head[u]=cnt,to[cnt]=v,val[cnt]=w;
}
int cnxt[MAXN],cval[MAXN];
void cadd(int u,int v,int w){
    cnxt[u]=v,cval[u]=w;
}
int d[MAXN],f[MAXN],root,csz;
bool vis[MAXN],cir[MAXN];
void dfs(int p,int fa){
    for(int i=head[p];i;i=nxt[i]){



        
        f[p]=max(f[p],d[t]+d[p]+val[i]);
        d[p]=max(d[p],d[t]+val[i]);
    }
}
deque<int> q;
int presum[MAXN<<1],cp[MAXN<<1];
void findD(int x){
    csz=0;
    dfs(x,0);
    while(!q.empty())q.pop_back();
    int ptr=1,fvis=2;
    int res=f[root];
    for(int i=root;;i=cnxt[i]){
        res=max(res,f[i]);
        if(i==root){
            if(fvis)fvis--;
            else break;
        }
        cp[ptr++]=i;
        presum[ptr]=presum[ptr-1]+cval[i];
    }
    fu(i,1,2*csz,1,1){
        while(!q.empty()&&i-q.front()>csz/2)q.pop_front();
        if(!q.empty())res=max(res,presum[i]-presum[q.front()]+d[cp[q.front()]]+d[cp[i]]);
        while(!q.empty()&&-presum[i]+d[cp[i]]>=-presum[q.back()]+d[cp[q.back()]])q.pop_back();
        q.push_back(i);
    }
    ans+=res;
}

signed main(){
    n=read();
    fu(i,1,n,1,1){
        int v=read(),w=read();
        add(i,v,w);add(v,i,w);
    }
    fu(i,1,n,1,1)if(!vis[i])findD(i);
    printf("%lld",ans);
}