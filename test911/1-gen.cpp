#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
int n,m;
inline int __abs(int x){return x<0?-x:x;}
bool f[1005][1005];
mt19937 rnd(time(NULL));
int main(){
	freopen("1.in","w",stdout);
	
	
	n=1000,m=1000;
	
	
	cout<<n<<" "<<m<<endl;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int k=rnd();
			k=__abs(k);
			k%=10000;
			if(k>9998){
				int p=rnd();
				p=__abs(p);
				p%=50;p+=10;
				if(i-p<=1||i+p>=n||j-p<=1||j+p>=m)
					continue;
				else{
				//	cerr<<"START";
					for(int sb_=i-p;sb_<=i+p;sb_++){
						int sbabs=p-__abs(sb_-i);
						for(int _abs=j-sbabs;_abs<=j+sbabs;_abs++)
							f[sb_][_abs]=1;
					}
				//	cerr<<"DRAW"<<endl;
				}
					
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)
			putchar(f[i][j]?'#':'.');
		puts("");
	}
}
