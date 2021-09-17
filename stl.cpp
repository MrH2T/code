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
namespace Homemade_STL{
    const int MAX_SIZE = 10005000;
    template<class T>
    class Queue{
        private:
            T q_element[MAX_SIZE];
            int head,tail;
        public:
            Queue(){memset (q_element,0,sizeof(q_element));head=1,tail=0;}
            T front(){return q_element[head];}
            T back(){return q_element[tail];}
            int size(){return tail-head+1;}
            bool empty(){return !size();}
            void pop(){if(size())head++;}
            void push(T n_ele){q_element[++tail]=n_ele;}
            typedef T* iterator;
            iterator begin(){return q_element+head;}
            iterator end(){return q_element+tail+1;}

            void reset(){head=1,tail=0;}
    };

    template <class T>
    class Stack{
        private:
            T s_element[MAX_SIZE];
            int _top;
        public:
            Stack(){memset(s_element,0,sizeof(s_element));_top=0;}
            T top(){return s_element[_top];}
            int size(){return _top;}
            bool empty(){return !size();}
            void pop(){if(size())_top--;}
            void push(T n_ele){s_element[++_top]=n_ele;}
            typedef T* iterator;
            iterator begin(){return s_element+1;}
            iterator end(){return s_element+_top+1;}

            void reset(){_top=0;}
    };
}
using namespace Homemade_STL;

Stack<int> q;
stack<int> qq;
signed main(){
    time_t t;

    printf("Test # Push:\n");
    t=clock();
    for(int i=1;i<=1e7;i++)q.push(1);
    printf("My Stack: %.3lfs\n",double(clock()-t)/(double)CLOCKS_PER_SEC);
    t=clock();
    for(int i=1;i<=1e7;i++)qq.push(1);
    printf("STL Stack: %.3lfs\n",double(clock()-t)/(double)CLOCKS_PER_SEC);

    printf("Test # Pop:\n");
    t=clock();
    for(int i=1;i<=1e7;i++)q.pop();
    printf("My Stack: %.3lfs\n",double(clock()-t)/(double)CLOCKS_PER_SEC);
    t=clock();
    for(int i=1;i<=1e7;i++)qq.pop();
    printf("STL Stack: %.3lfs\n",double(clock()-t)/(double)CLOCKS_PER_SEC);
}