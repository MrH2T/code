#include<cstdio>
#include<cstring>
using namespace std;
int T,n,sg[25],a[25];
int init(int n){//???sg[n] 
	bool vis[105]={}; 
	if(sg[n]!=-1) return sg[n];//??? 
	if(n==1) return sg[1]=0;//?? 
	for(int i=1;i<n;i++){
		for(int j=1;j<=i;j++) vis[init(i)^init(j)]=1;//?????:sg[i][j] 
	}
	for(int i=0;;i++) if(!vis[i]) return sg[n]=i;
}
int main(){
	scanf("%d",&T);
	memset(sg,-1,sizeof(sg));
	for(int i=1;i<=21;i++)
		if(sg[i]==-1) init(i);//???sg??? 
	while(T--){
		scanf("%d",&n);
		int ans=0,ans1=0,vi=0,vj=0,vk=0;//ans???????sg? ans1???????? 
										//vi,vj,vk????0,-1??????,??????????? 
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if(a[i]&1) ans^=sg[n-i+1];//??i%2==1?????????? 
		}
		for(int i=1;i<=n-1;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j;k<=n;k++){
					if(!(ans^sg[n-i+1]^sg[n-j+1]^sg[n-k+1])){
						if(vi==0) vi=i,vj=j,vk=k;
						ans1++;
					}
				}
			}
		}
		printf("%d %d %d\n%d\n",vi-1,vj-1,vk-1,ans1);
	}
	return 0;
}
