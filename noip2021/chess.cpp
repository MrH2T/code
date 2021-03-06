/*
1-6  : brute-force simulation  O(nmq)
7-8  : simple check O(q)
9-11 : tag all the straight-roads and work (?)
12-14: no idea
15-16: all the other's chess is useless
17-18: all the chess is obstacle
19-25: no idea (if 15-18 is solved, then i think it's nearly done)
*/

#include<bits/stdc++.h>
#define rint register int
#define fu(i,a,b,d,c) for(rint i=a;i<=b&&c;i+=d)
#define fd(i,a,b,d,c) for(rint i=a;i>=b&&c;i-=d)
using namespace std;
inline int read(){
    char c=0,f=1;int num=0;
    while(c<'0'||c>'9')((c=getchar())=='-')&&(f=-f);
    while(c>='0'&&c<='9')num=(num<<1)+(num<<3)+(c^48),c=getchar();
    return num*f;
}
const int MAXNM = 200050;
int n,m,q,T;
inline int ID(int x,int y){return (x-1)*m+y;}
inline int X(int id){return (id-1)/m+1;}
inline int Y(int id){return (id-1)%m+1;}
char s[MAXNM];
int cnt,head[MAXNM],to[MAXNM<<2],val[MAXNM<<2],nxt[MAXNM<<2],di[MAXNM<<2];
void add(int u,int v,int w,int dr){
    nxt[++cnt]=head[u],head[u]=cnt,to[cnt]=v,val[cnt]=w,di[cnt]=dr;
}
int col[MAXNM],lv[MAXNM];
namespace Subtask1{
    //1-6
    int tms,rs=0;
    int vis[MAXNM];
    void dfs(int u,int c,int l,int tp,int d){
        vis[u]=tms;
        for(int i=head[u];i;i=nxt[i]){
            int v=to[i];
            if(vis[v]==tms||val[i]!=tp||(tp==2&&di[i]!=d))continue;
            if(col[v]==c)continue;
            else if(col[v]&&lv[v]<=l){vis[v]=tms;continue;}
            else if(!col[v])dfs(v,c,l,tp,d);
        }
    }
    int check(int x,int y,int c,int l){
        memset(vis,0,sizeof(vis));
        int u=ID(x,y);
        vis[u]=++tms;
        int res=0;
        for(int i=head[u];i;i=nxt[i]){
            int v=to[i];
            if(col[v]==c)continue;
            else if(col[v]&&lv[v]<=l)vis[v]=++tms;
            else if(!col[v]){
                if(val[i]==1)vis[v]=++tms;
                else {
                    tms++;
                    dfs(v,c,l,val[i],di[i]);
                }
            }
        }
        fu(i,1,n*m,1,1)if(vis[i])res++;
        res--;
        return res;
    }
    void solve(){
        while(q--){
            int c=read()+1,l=read(),x=read(),y=read();
            printf("%d\n",check(x,y,c,l));
            col[ID(x,y)]=c,lv[ID(x,y)]=l;
        }
    }
}
namespace Subtask2{
    //7-8
    void solve(){
        while(q--){
            int c=read()+1,l=read(),x=read(),y=read();
            int u=ID(x,y),ans=0;
            for(int i=head[u];i;i=nxt[i]){
                int v=to[i];
                if(col[v]==c)continue;
                else if(!col[v]||lv[v]<=l)ans++;
            }
            printf("%d\n",ans);
            col[u]=c,lv[u]=l;
        }
    }
}
int work(){
    memset(head,0,sizeof(head));
    memset(col,0,sizeof(col));
    memset(lv,0,sizeof(lv));
    cnt=0;
    scanf("%d %d %d\n",&n,&m,&q);
    bool e2=0,e3=0;
    fu(i,1,n,1,1){
        scanf("%s\n",s+1);
        fu(j,1,m-1,1,1)
            if(s[j]-'0')
            add(ID(i,j),ID(i,j+1),s[j]-'0',1),add(ID(i,j+1),ID(i,j),s[j]-'0',1),
            (s[j]=='2')&&(e2=1),(s[j]=='3')&&(e3=1);
    }
    fu(i,1,n-1,1,1){
        scanf("%s\n",s+1);
        fu(j,1,m,1,1)
            if(s[j]-'0')
            add(ID(i,j),ID(i+1,j),s[j]-'0',2),add(ID(i+1,j),ID(i,j),s[j]-'0',2),
            (s[j]=='2')&&(e2=1),(s[j]=='3')&&(e3=1);
    }
    if(n*m<=5000){
        Subtask1::solve();
        return 0;
    }
    else if(!e2&&!e3){
        Subtask2::solve();
        return 0;
    }
    else if(!e3){
		while(q--){read(),read(),read(),read();}
    }
    else if(!e2){
		while(q--){read(),read(),read(),read();}
    }
    else {
    	while(q--){read(),read(),read(),read();}
	}
    return 0;
}
signed main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	
    T=read();
    while(T--)work();
    return 0;
}
