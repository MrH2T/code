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
const int MAXN = 505, MAXM = 125050;
int n,m;
int cnt=1,head[MAXN],nxt[MAXM<<1],to[MAXM<<1],deg[MAXN];
void add(int u,int v){nxt[++cnt]=head[u],head[u]=cnt,to[cnt]=v;}

double a[MAXN][MAXN],b[MAXN];

double val[MAXM<<1];
signed main(){
    n=read(),m=read();
    fu(i,1,m,1,1){int u=read(),v=read();add(u,v),add(v,u);deg[u]++,deg[v]++;}

    fu(i,1,n,1,1){
        a[i][i]=-1.0f;
        for(int j=head[i];j;j=nxt[j])if(to[j]^n){
            a[i][to[j]]=1.0/double(deg[to[j]]);
        }
    }
    b[1]=-1.0f;
    fu(i,1,n,1,1)a[n][i]=0;
    b[n]=1,a[n][n]=1.0f;

    fu(i,1,n,1,1){
        fu(j,i,n,1,1)if(a[j][i]){
            fu(k,1,n,1,1)swap(a[i][k],a[j][k]);
            swap(b[i],b[j]);
            break;
        }
        fu(j,1,n,1,1)if(j!=i&&a[j][i]){
            double rate=-a[j][i]/a[i][i];
            fu(k,1,n,1,1)a[j][k]+=rate*a[i][k];
            b[j]+=rate*b[i];
        }
    }
    
    fu(i,1,n-1,1,1){
    	for(int j=head[i];j;j=nxt[j])
    		val[j]+=b[i]/a[i][i]/deg[i],val[j^1]+=b[i]/a[i][i]/deg[i];
	}
	sort(val+2,val+cnt+2,greater<double>());
	double ans=0.0f;
	fu(i,2,cnt,2,1)ans+=i/2*val[i];
	printf("%.3lf",ans);
}
