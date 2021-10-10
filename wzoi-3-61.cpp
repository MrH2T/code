#pragma GCC optimize("Ofast")
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
const int MAXN = 100050, MAXD = 400;
int n,a[MAXN];
int rtn,tp/*time post*/;
int ans[MAXN];
int bk[MAXN],bkk[MAXD][MAXN];
int kds[MAXD],r[MAXD];

void solve(int k){			//this is a rubbish
    tp++;
    int kd=0,an=0;
    fu(i,1,n,1,1){
    	if(bk[a[i]]!=tp){
    		if(++kd>k){
    			an++;
    			kd=1;
    			tp++;
			}
			bk[a[i]]=tp;
		}
	}
	if(tp)an++;
    ans[k]=an;
}

signed main(){
    n=read();fu(i,1,n,1,1)a[i]=read();
    rtn=sqrt(n);
    fu(i,1,rtn,1,1){	//this is a rubbish
        solve(i);
    }
    if(rtn<n){
        //first solve k=rtn+1
        int blk=1;
        fu(i,1,n,1,1){
            if(!bkk[blk][a[i]]&&kds[blk]==rtn+1)r[blk++]=i;
            if(!bkk[blk][a[i]]++)kds[blk]++;
        }
        r[ans[rtn+1]=blk]=n+1;
        
        fu(i,rtn+2,n,1,1){	//are they different?
        	fu(j,1,blk,1,1)
        	while(r[j]<=n){
        		if(!bkk[j][a[r[j]]]&&kds[j]==i)break;
				if(!--bkk[j+1][a[r[j]]])kds[j+1]--;
				if(!bkk[j][a[r[j]++]]++)kds[j]++;
			}
			while(blk>1&&r[blk-1]>n)blk--;
			ans[i]=blk;
        }
    }
    fu(i,1,n,1,1)printf("%d ",ans[i]);
}
