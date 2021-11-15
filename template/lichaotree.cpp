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
typedef pair<double,int> pr;
const int MAXN = 100050, LJC = 39989, MOD = 1e9;
struct Line{double k,b;double operator()(int x){return k*x+b;}}line[MAXN];
int tr[LJC<<2];
int cnt;
#define ls p<<1
#define rs p<<1|1
inline int newnd(int x,int y,int xx,int yy){
    cnt++;
    if(x==xx){line[cnt]=(Line){0,1.0f*max(y,yy)};}
    else {line[cnt]=(Line){double(yy-y)/double(xx-x),y-double(yy-y)/double(xx-x)*x};}
    return cnt;
}
void insert(int p,int l,int r,int ll,int rr,int x){
    if(rr<l||ll>r)return ;
    int y=tr[p];
    int mid=l+r>>1;
    double rx=line[x](mid),ry=line[y](mid);
    if(ll<=l&&r<=rr){
        if(l==r)return void(rx>ry?tr[p]=x:0);
        if(line[x].k<line[y].k){
            if(rx>ry)tr[p]=x,insert(rs,mid+1,r,ll,rr,y);
            else insert(ls,l,mid,ll,rr,x);
        }
        else if(line[x].k>line[y].k){
            if(rx>ry)tr[p]=x,insert(ls,l,mid,ll,rr,y);
            else insert(rs,mid+1,r,ll,rr,x);
        }
        else tr[p]=rx>ry?x:y;
        return ;
    }
    insert(ls,l,mid,ll,rr,x);
    insert(rs,mid+1,r,ll,rr,x);
}
pr mx(pr a,pr b){
    if(a.first!=b.first)return a.first>b.first?a:b;
    else return a.second<b.second?a:b;
}
pr query(int p,int l,int r,int x){
    if(x<l||x>r)return make_pair(0,0);
    int mid=l+r>>1;
    double res=line[tr[p]](x);
    if(l==r)return make_pair(res,tr[p]);
    return mx(make_pair(res,tr[p]),mx(query(ls,l,mid,x),query(rs,mid+1,r,x)));
}
int n;
signed main(){
    n=read();int las=0;
    fu(i,1,n,1,1){
        int op=read();
        if(op==1){
            int x=read(),y=read(),xx=read(),yy=read();
            x=(x+las+LJC-1)%LJC+1,xx=(xx+las+LJC-1)%LJC+1;
            y=(y+las+MOD-1)%MOD+1,yy=(yy+las+MOD-1)%MOD+1;
            if(x>xx)swap(x,xx),swap(y,yy);
            insert(1,1,LJC,x,xx,newnd(x,y,xx,yy));
        }
        else{
            int x=read();
            x=(x+las+LJC-1)%LJC+1;
            printf("%d\n",(las=query(1,1,LJC,x).second));
        }
    }
}