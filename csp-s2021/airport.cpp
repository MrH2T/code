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
const int MAXN = 100050;
struct flight{
    int st,et;
    flight(){st=et=0;}
}a[MAXN],b[MAXN];
bool cmp(flight a,flight b){return a.st<b.st;}
int n,m1,m2;
int sz1[MAXN],sz2[MAXN],sum1[MAXN],sum2[MAXN];
int id1,id2;
typedef pair<int,int> pr;
priority_queue<pr,vector<pr>, greater<pr> > q;
priority_queue<int,vector<int> ,greater<int> >qtmp;
signed main(){
    freopen("airport.in","r",stdin);
    freopen("airport.out","w",stdout);
    n=read(),m1=read(),m2=read();
    fu(i,1,m1,1,1)a[i].st=read(),a[i].et=read();
    fu(i,1,m2,1,1)b[i].st=read(),b[i].et=read();
    sort(a+1,a+m1+1,cmp),sort(b+1,b+m2+1,cmp);

    // fu(i,1,m1,1,1)printf("%d %d\n",a[i].st,a[i].et);
    // fu(i,1,m2,1,1)printf("%d %d\n",b[i].st,b[i].et);

    while(!q.empty())q.pop();
    while(!qtmp.empty())qtmp.pop();
    if(m1)sz1[++id1]=1,q.push(make_pair(a[1].et,id1));
    fu(i,2,m1,1,1){
        if(!qtmp.empty()||!q.empty()&&q.top().first<a[i].st){
            while(!q.empty()&&q.top().first<a[i].st){
                qtmp.push(q.top().second),q.pop();
            }
            int tp=qtmp.top();qtmp.pop();
            sz1[tp]++;
            q.push(make_pair(a[i].et,tp));
        }
        else sz1[++id1]=1,q.push(make_pair(a[i].et,id1));
    }
    while(!q.empty())q.pop();
    while(!qtmp.empty())qtmp.pop();
    if(m2)sz2[++id2]=1,q.push(make_pair(b[1].et,id2));
    fu(i,2,m2,1,1){
        if(!qtmp.empty()||!q.empty()&&q.top().first<b[i].st){
            while(!q.empty()&&q.top().first<b[i].st){
                qtmp.push(q.top().second),q.pop();
            }
            int tp=qtmp.top();qtmp.pop();
            sz2[tp]++;
            q.push(make_pair(b[i].et,tp));
        }
        else sz2[++id2]=1,q.push(make_pair(b[i].et,id2));
    }
    
    fu(i,1,n,1,1)sum1[i]=sum1[i-1]+sz1[i];
    fu(i,1,n,1,1)sum2[i]=sum2[i-1]+sz2[i];
    // fu(i,1,n,1,1)printf("%d ",sz1[i]);putchar('\n');
    // fu(i,1,n,1,1)printf("%d ",sz2[i]);putchar('\n');
    int ans=0;
    fu(i,0,n,1,1){
        ans=max(ans,sum1[i]+sum2[n-i]);
    }
    printf("%d",ans);
    return 0;
}