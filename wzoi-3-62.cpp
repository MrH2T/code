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
typedef long long ll;
const int MAXN = 100010, MAXD=320,MOD = 998244353;
int n,m,rtn;
int c[MAXN];
int blk,lb[MAXD],rb[MAXD],blknum[MAXD][MAXN];
int cnt[MAXN];
ll a[MAXN],blksum[MAXD],blkadd[MAXD][MAXN];

set<int> pos[MAXN];

inline int ofblk(int x){
    return (x-1)/rtn+1;
}
ll getsum(int l,int r){
    int bl=ofblk(l),br=ofblk(r);
    ll ret=0;
    if(bl==br){ //O(sqrt n)
        fu(i,l,r,1,1)ret=(ret+a[i]+blkadd[bl][c[i]]);
        return ret%MOD;
    }
    //O(sqrt n)
    if(l!=lb[bl]){  
        fu(i,l,rb[bl],1,1)ret=(ret+a[i]+blkadd[bl][c[i]]);
        bl++;
    }
    if(r!=rb[br]){
        fd(i,r,lb[br],1,1)ret=(ret+a[i]+blkadd[br][c[i]]);
        br--;
    }
    fu(i,bl,br,1,1)ret=(ret+blksum[i]);
    return ret%MOD;
}

signed main(){
    n=read(),m=read();
    rtn=sqrt(n);
    fu(i,1,n,1,1){
        cnt[c[i]=read()]++;
        blknum[ofblk(i)][c[i]]++;
        pos[c[i]].insert(i);
    }
    fu(i,1,n/rtn,1,1)blk++,lb[i]=rb[i-1]+1,rb[i]=lb[i]+rtn-1;
    if(rb[blk]!=n)blk++,lb[blk]=rb[blk-1]+1,rb[blk]=n;
    fu(i,1,m,1,1){
        int op=read();
        if(op==1){  //add [l,r] color_x of y
            int l=read(),r=read(),x=read(),y=read();
            if(cnt[x]<=rtn){
                //O((sqrt n)*log(sqrt n))
                for(set<int>::iterator j=pos[x].begin();j!=pos[x].end();j++){
                    if(*j>=l&&*j<=r){
                        (blksum[ofblk(*j)]+=y)%=MOD;
                        (a[*j]+=y)%=MOD;
                    }
                }
            }else{  //key color
                int bl=ofblk(l),br=ofblk(r);
                if(bl==br){ //O(sqrt n)
                    fu(j,l,r,1,1)if(c[j]==x)(blksum[bl]+=y)%=MOD,(a[j]+=y)%=MOD;
                    continue;
                }
                if(l!=lb[bl]){       //O(sqrt n)
                    fu(j,l,rb[bl],1,1)if(c[j]==x)(blksum[bl]+=y)%=MOD,(a[j]+=y)%=MOD;
                    bl++;
                }     
                if(r!=rb[br]){  //O(sqrt n)
                    fd(j,r,lb[br],1,1)if(c[j]==x)(blksum[br]+=y)%=MOD,(a[j]+=y)%=MOD;
                    br--;
                }
                fu(j,bl,br,1,1){    //O(sqrt n)
                    (blksum[j]+=1LL*blknum[j][x]*y)%MOD;
                    (blkadd[j][x]+=y)%=MOD;
                }
            }
        }
        else if(op==2){ // query sum [l,r]
            int l=read(),r=read();
            printf("%lld\n",getsum(l,r));
        }
        else {  //modify color at x to y
            int x=read(),y=read();
            if(c[x]==y)continue;
            int bb=ofblk(x);
            (a[x]+=blkadd[bb][c[x]])%=MOD;
            fu(j,lb[bb],rb[bb],1,1)if(c[j]==y)(a[j]+=blkadd[bb][y])%=MOD;
            blkadd[bb][y]=0;
            pos[c[x]].erase(x);
            cnt[c[x]]--,blknum[bb][c[x]]--;
            c[x]=y;
            pos[y].insert(x);
            cnt[y]++,blknum[bb][y]++;
        }
    }
}