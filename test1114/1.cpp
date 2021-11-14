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
const int MAXN = 2050;
int n,m,fa[MAXN];
inline int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
bool book[MAXN];
int x[MAXN],y[MAXN],z[MAXN];
set<int> ant[MAXN];
int col[MAXN];
signed main(){
	n=read(),m=read();
	iota(fa,fa+n+1,0);
	fu(i,1,m,1,1){
		x[i]=read(),y[i]=read(),z[i]=read();
        fu(j,0,z[i]-1,1,1){
            int u=find(x[i]+j),v=find(y[i]+j);
            if(u<v)fa[v]=u;
            else fa[u]=v;
        }
	}
    fu(i,1,m,1,1){
        if(x[i]+z[i]>n||y[i]+z[i]>n)continue;
        int u=find(x[i]+z[i]),v=find(y[i]+z[i]);
        if(u==v)return printf("-1")&0;
        if(u<v)ant[v].insert(u);
        else ant[u].insert(v);
    }
	fu(i,1,n,1,1){
		int fuc=find(i);
		if(fuc==i){
			memset(book,0,sizeof(book));
			for(auto j:ant[i])book[col[j]]=1;
			fu(j,0,n,1,1)if(!book[j]){col[i]=j;break;}
		}
		else col[i]=col[fuc];
	}
	fu(i,1,n,1,1)printf("%d ",col[i]);
}