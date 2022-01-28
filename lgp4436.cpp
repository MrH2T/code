//not the good code
//struggle with O2 in luogu
//tle at loj

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
const int MAXN = 1e6+50;
int n,m,p,id_,id[MAXN],lb[MAXN],rb[MAXN],key[MAXN],kkk[MAXN],lgn;
int mn[MAXN][21];
void solve(int p){
    bool flag=1;
    while(flag){
        flag=0;
        if(lb[p]>1 && lb[p]<=kkk[lb[p]-1] && kkk[lb[p]-1]<=rb[p])lb[p]--,flag=1;
        if(rb[p]<id_ && lb[p]<=kkk[rb[p]] && kkk[rb[p]]<=rb[p])rb[p]++,flag=1;
    }
}
inline int mxx(int a,int b){return a>b?a:b;}
inline int mnn(int a,int b){return a<b?a:b;}
inline int near(int x,int fr){
    fd(i,lgn,0,1,1){
        if(fr+(1<<i)-1>id_)continue;
        if(mn[fr][i]>x)fr=fr+(1<<i);
    }
    return fr+(kkk[fr+1]<=x);
}
signed main(){
    n=read(),m=read(),p=read();
    lgn=ceil(log2(n));
    fu(i,1,m,1,1){int x=read(),y=read();key[x]=y;}
    id_=id[1]=1;
    fu(i,2,n,1,1){
        if(!key[i-1])id[i]=id_;
        else kkk[id_]=key[i-1],id[i]=++id_;
    }
    iota(lb+1,lb+id_+1,1);
    iota(rb+1,rb+id_+1,1);
    fu(i,1,n,1,1)kkk[i]=id[kkk[i]];
    kkk[id_]=id_+1;
    fu(i,1,id_,1,1)mn[i][0]=kkk[i];
    fu(k,1,lgn,1,1)fu(i,1,id_,1,1)if(i+(1<<k-1)>n)break;else mn[i][k]=mnn(mn[i][k-1],mn[i+(1<<k-1)][k-1]);
    
    // printf("kkk: ");
    // fu(i,1,id_,1,1)printf("%d ",kkk[i]);
    // printf("\n");

    solve(1);
    fu(i,2,id_,1,1){
        if(kkk[i-1]<i){
            lb[i]=i;
            if(rb[i-1]>=i)rb[i]=mxx(i,mnn(rb[i-1],near(i-1,i)));
            else while(rb[i]<id_ && lb[i]<=kkk[rb[i]] && kkk[rb[i]]<=rb[i])rb[i]++;
        }else{
            while(rb[i]<id_ && lb[i]<=kkk[rb[i]] && kkk[rb[i]]<=rb[i])rb[i]++;
            if(kkk[i-1]<=rb[i])lb[i]=lb[i-1],solve(i);
        }
    }
    // fu(i,1,id_,1,1)printf("lb rb: %d %d\n",lb[i],rb[i]);
    fu(i,1,p,1,1){
        int s=read(),t=read();
        if(lb[id[s]]<=id[t] && id[t]<=rb[id[s]])printf("YES\n");
        else printf("NO\n");
    }
}