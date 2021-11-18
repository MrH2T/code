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
const int MAXN = 100050;
struct Treap{
    struct node{
        int val,dat;
        int cnt,sz;
        int son[2];
    }tr[MAXN];
    #define val(p) tr[p].val
    #define dat(p) tr[p].dat
    #define cnt(p) tr[p].cnt
    #define sz(p) tr[p].sz
    #define son(p) tr[p].son
    #define ls tr[p].son[0]
    #define rs tr[p].son[1]
    int cnt,root;
    void push_up(int p){
        sz(p)=sz(ls)+sz(rs)+cnt(p);
    }
    void rotate(int &p,int d){
        int k=son(p)[d^1];
        son(p)[d^1]=son(k)[d];
        son(k)[d]=p;
        push_up(p);
        push_up(k);
        p=k;
    }
    void insert(int &p,int x){
        if(!p){
            p=++cnt;
            val(p)=x;
            sz(p)=cnt(p)=1;
            dat(p)=rand();
            return;
        }
        if(val(p)==x){
            sz(p)++,cnt(p)++;
            return;
        }
        int d=x>val(p);
        insert(son(p)[d],x);
        if(dat(son(p)[d])>dat(p))rotate(p,d^1);
        push_up(p);
    }
    void del(int &p,int x){
        if(x<val(p))del(ls,x);
        else if(x>val(p))del(rs,x);
        else{
            if(!son(p)[0]&&!son(p)[1]){
                sz(p)--,cnt(p)--;
                if(!cnt(p))p=0;
            }
            else if(son(p)[0]&&!son(p)[1]){
                rotate(p,1);
                del(rs,x);
            }
            else if(!son(p)[0]&&son(p)[1]){
                rotate(p,0);
                del(ls,x);
            }
            else{
                int d=dat(ls)>dat(rs);
                rotate(p,d);
                del(son(p)[d],x);
            }
        }
        push_up(p);
    }
    int getRank(int p,int x){
        if(!p)return 0;
        if(val(p)==x)return sz(ls);
        else if(val(p)>x)return getRank(ls,x);
        else return sz(ls)+cnt(p)+getRank(rs,x);
    }
    int find(int p,int x){
        if(!p)return 0;
        if(x<=sz(ls))return find(ls,x);
        else if(sz(ls)+cnt(p)<x)return find(rs,x-sz(ls)-cnt(p));
        else return val(p);
    }
    int getPre(int p,int x){
        if(!p)return 0x80000001;
        if(val(p)>=x)return getPre(ls,x);
        else return max(val(p),getPre(rs,x));
    }
    int getSuc(int p,int x){
        if(!p)return 0x7fffffff;
        if(val(p)<=x)return getSuc(rs,x);
        else return min(val(p),getSuc(ls,x));
    }
    void insert(int x){insert(root,x);}
    void del(int x){del(root,x);}
    int getRank(int x){return getRank(root,x);}
    int find(int x){return find(root,x);}
    int getPre(int x){return getPre(root,x);}
    int getSuc(int x){return getSuc(root,x);}
}treap;
int n;
signed main(){
    n=read();
    fu(i,1,n,1,1){
        int op=read(),x=read();
        if(op==1)treap.insert(treap.root,x);
        else if(op==2)treap.del(treap.root,x);
        else if(op==3)printf("%d\n",treap.getRank(treap.root,x)+1);
        else if(op==4)printf("%d\n",treap.find(treap.root,x));
        else if(op==5)printf("%d\n",treap.getPre(treap.root,x));
        else printf("%d\n",treap.getSuc(treap.root,x));
    }
}