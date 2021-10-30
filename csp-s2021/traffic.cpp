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
const int MAXN = 550 ,MAXK=55;
namespace dij{
    namespace gra{
        int cnt,head[MAXN*MAXN<<1],nxt[MAXN*MAXN<<3],to[MAXN*MAXN<<3],val[MAXN*MAXN<<3];
        void add(int u,int v,int w){
            nxt[++cnt]=head[u],head[u]=cnt,to[cnt]=v,val[cnt]=w;
        }
    }
    priority_queue<pair<int,int> >q;
    int vis[MAXN*MAXN],dis[MAXN*MAXN];
    int dj(int s,int t){
        while(!q.empty())q.pop();
        memset(vis,0,sizeof(vis)),memset(dis,0x3f,sizeof(dis));
        dis[s]=0;
        q.push(make_pair(0,1));
        while(!q.empty()){
            int x=q.top().second;q.pop();
            if(vis[x])continue;
            vis[x]=1;
            for(int i=gra::head[x];i;i=gra::nxt[i]){
                if(dis[gra::to[i]]>dis[x]+gra::val[i]){
                    dis[gra::to[i]]=dis[x]+gra::val[i];
                    q.push(make_pair(-dis[gra::to[i]],gra::to[i]));
                }
            }
        }
        return dis[t];
    }
}
int T,cnt0;
int n,m,val[MAXN][MAXN][2]; // 0 - down , 1 - right
int tmpv[MAXK],line[MAXK],col[MAXK];

#define toId(x,y) ((x-1)*m+y)
const int b1=250001,b2=250002;
int blk(int l,int l1,int l2){
    if(l1<l&&l<l2)return b2;
    if(l<l1||l>l2)return b1;
}
void lk(int l1,int l2){
    
}

signed main(){
    n=read(),m=read(),T=read();
    fu(i,1,n-1,1,1)fu(j,1,m,1,1)val[i][j][0]=read()
    fu(i,1,n,1,1)fu(j,1,m-1,1,1)val[i][j][1]=read();
    if(n!=2)fu(i,1,m-1,1,1)
        dij::gra::add(toId(1,i),toId(2,i)),
        dij::gra::add(toId(n-1,i),toId(n-2,i));
    if(m!=2)fu(i,1,n-1,1,1)
        dij::gra::add(toId(i,1),toId(i,2)),
        dij::gra::add(toId(i,m-1),toId(i,m-2));
    cnt0=dij::gra::cnt;
    while(T--){
        int k=read();
        if(k==0||k==1){printf("0\n");continue;}
        if(k==2){
            fu(i,1,k,1,1)tmpv[i]=read(),line[i]=read(),col[i]=read();
            if(col[1]==col[2]){printf("0\n");continue;}
            if(line[1]>line[2])swap(line[1],line[2]),swap(tmpv[1],tmpv[2]),swap(col[1],col[2]);
            if(line[1]==1&&line[2]==2*(n+m)||line[1]==m&&line[2]==m+1
                ||line[1]==n+m&&line[2]==n+m+1||line[1]==n+2*m&&line[2]==n+2*m+1)
                {printf("0\n");continue;}
            lk(line[1],line[2],b1,b2);
            printf("%d\n",dij::dj(b1,b2));
            continue;
        }
        else{
            printf("FuckCCF\n");
            return 0;
        }
    }
}