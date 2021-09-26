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
const int MAXN = 1050;
int n,m,l,r;
int a[MAXN],b[MAXN],c[MAXN];
int son[MAXN][250][3],f[MAXN][250];
int ind(int x){return (x>100?100:x<-100?-100:x)+101;};
signed main(){
//	freopen("1.out","w",stdout);
    n=read(),m=read(),l=read(),r=read();
    fu(i,1,n,1,1)a[i]=read(),b[i]=read(),c[i]=read();
    int valmin=-100,valmax=100;
    fu(j,valmin,valmax,1,1)f[n][ind(j)]=(j<=l)?(-1):(j>=r)?1:0;
    fd(i,n,1,1,1){
        fu(j,valmin,valmax,1,1){
            if(a[i])son[i-1][ind(j-a[i])][++son[i-1][ind(j-a[i])][0]]=ind(j);
            if(b[i])son[i-1][ind(j+b[i])][++son[i-1][ind(j+a[i])][0]]=ind(j);
            if(c[i])son[i-1][ind(-j)][++son[i-1][ind(-j)][0]]=ind(j);
        }
        fu(j,valmin,valmax,1,1){
        	int col=i&1;
        	int hav1=0,havn1=0,hav0=0;
            fu(k,1,son[i-1][ind(j)][0],1,1){
            	if(f[i][son[i-1][ind(j)][k]]==1)hav1=1;
            	if(f[i][son[i-1][ind(j)][k]]==-1)havn1=1;
            	if(f[i][son[i-1][ind(j)][k]]==-0)hav0=1;
			}
			if(col){
				if(hav1)f[i-1][ind(j)]=1;
				else if(hav0)f[i-1][ind(j)]=0;
				else f[i-1][ind(j)]=-1;
			}else{
				if(havn1)f[i-1][ind(j)]=-1;
				else if(hav0)f[i-1][ind(j)]=0;
				else f[i-1][ind(j)]=1;
			}
        }
    }
//     fu(j,-20,20,1,1)printf("%4d ",j);puts("");
//     fu(i,0,n,1,1){
//     	fu(j,-20,20,1,1)printf("%4d ",f[i][ind(j)]);
//     	puts("");
//	 }
    printf("%s",f[0][ind(m)]==1?"HE":f[0][ind(m)]==-1?"BE":"NE");
}
