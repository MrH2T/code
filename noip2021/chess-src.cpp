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
    struct tri{int u,v,w;};
    queue<tri> qq;
    bool vis[MAXNM];
    int bfs(int x,int y,int c,int l){
        while(!qq.empty())qq.pop();
        memset(vis,0,sizeof(vis));
        int u=ID(x,y);
        vis[u]=1;
        int res=0;
        for(int i=head[u];i;i=nxt[i]){
            int v=to[i];
            if(col[v]==c)continue;
            else if(col[v]&&lv[v]<=l)res++;
            else if(!col[v]){
                qq.push((tri){v,val[i],di[i]});
            }
        }
        while(!qq.empty()){
            tri fr=qq.front();qq.pop();
            vis[fr.u]=1,res++;
            int tp=fr.v,u=fr.u,d=fr.w;
            for(int i=head[u];i;i=nxt[i]){
                int v=to[i];
                if(col[v]==c)continue;
                if(col[v]&&lv[v]<=l&&val[i]==tp&&!vis[v]&&(tp!=2||tp==2&&di[i]==d))vis[v]=1,res++;
                else if(!col[v]&&val[i]==tp&&!vis[v]&&(tp!=2||tp==2&&di[i]==d)){
                    qq.push((tri){v,tp,d});
                }
            }
        }
        return res;
    }
    void solve(){
        while(q--){
            int c=read()+1,l=read(),x=read(),y=read();
            printf("%d\n",bfs(x,y,c,l));
            col[ID(x,y)]=c,lv[ID(x,y)]=l;
        }
    }
}
namespace Subtask2{
    //7-8
    void solve(){
        while(q--){
            // printf("%d\b\b\b\b\b",q);
            int c=read()+1,l=read(),x=read(),y=read();
            int u=ID(x,y),ans=0;
            // printf("u:%d\n",u);
            for(int i=head[u];i;i=nxt[i]){
                // printf("%d\n",i);
                // if(nxt[i]==i)exit(-1);
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
	// freopen("chess7.in","r",stdin);
	// freopen("chess.out","w",stdout);
	
    T=read();
    while(T--)work();
    return 0;
}
