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
const int MAXN = 64050;
int n;
namespace BIT{
    struct data{
        int val,pos;
    };
    inline data max(data a,data b){return a.val>b.val?a:b;}
    data tr[MAXN];
    void modify(int x,data v){
        for(;x<=n;x+=x&-x)tr[x]=max(tr[x],v);
    }
    data query(int x){
        data res=(data){0,0};
        for(;x;x-=x&-x)res=max(res,tr[x]);
        return res;
    }
    void modify1(int x,data v){
        for(;x;x-=x&-x)tr[x]=max(tr[x],v);
    }
    data query1(int x){
        data res=(data){0,0};
        for(;x<=n;x+=x&-x)res=max(res,tr[x]);
        return res;
    }
}
using namespace BIT;

int a[MAXN],lpre[MAXN],lsuc[MAXN];
int apre[MAXN],apre1[MAXN];
int solved=0;
vector<vector<int> >ans;
signed main(){
    n=read();
    lsuc[0]=1;
    fu(i,1,n,1,1)a[i]=read(),lpre[i]=i-1,lsuc[i]=i+1;
    while(solved<n){
        memset(tr,0,sizeof(tr));
        int mxl=0,mxid=0,mxl1=0,mxid1=0;
        for(rint i=lsuc[0];i<=n;i=lsuc[i]){
            int v=a[i];
            data pr=query(v-1);
            modify(v,(data){pr.val+1,i});
            apre[i]=pr.pos;
            if(pr.val+1>mxl)mxl=pr.val+1,mxid=i;
        }
        memset(tr,0,sizeof(tr));
        for(rint i=lsuc[0];i<=n;i=lsuc[i]){
            int v=a[i];
            data pr=query1(v+1);
            modify1(v,(data){pr.val+1,i});
            apre1[i]=pr.pos;
            if(pr.val+1>mxl1)mxl1=pr.val+1,mxid1=i;
        }
        vector<int> tmp;tmp.clear();
        if(mxl>=mxl1){
            int cur=mxid;
            while(cur){
                tmp.push_back(cur);
                lpre[lsuc[cur]]=lpre[cur];
                lsuc[lpre[cur]]=lsuc[cur];
                solved++;
                cur=apre[cur];
            }
        }else{
            int cur=mxid1;
            while(cur){
                tmp.push_back(cur);
                lpre[lsuc[cur]]=lpre[cur];
                lsuc[lpre[cur]]=lsuc[cur];
                solved++;
                cur=apre1[cur];
            }
        }
        ans.push_back(tmp);
    }
    int sz=ans.size();
    printf("%d\n",sz);
    fu(i,0,sz-1,1,1){
        int szz=ans[i].size();
        printf("%d ",szz);
        fd(j,szz-1,0,1,1)printf("%d ",a[ans[i][j]]);
        printf("\n");
    }
}  
