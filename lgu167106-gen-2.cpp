#include<bits/stdc++.h>
#define ll long long
const int N=500000,Q=500000;
using namespace std;
int l,r,len,num,k;
int book[50000005],st[5000005],ed[5000005];
int random(int l,int r){
	return (rand()*rand()%(r-l+1))+l;
}
int main(){
	freopen("data.in","w",stdout);
	srand(time(NULL));
	printf("%d\n",N);
	for(register int i=1;i<=N;i++){
		if(num){
			printf("%d ",k);
			num--;
		}
		else{
			int p=rand()%3;
			if(p==1){
				srand(rand());
				k=random(1,1e9);
				num=(rand()%2==1)?random(N/30000,N/10000):random(N/3000,N/1000);
				printf("%d ",k);
				book[++len]=k;
				st[len]=i,ed[len]=i+num-1;
				continue;
			}
			else{
				ll a=(ll)rand()*(ll)rand()*(ll)rand()%(ll)1e9;
				printf("%lld ",a);
			}
		}
	}
	printf("\n%d\n",Q);
	for(register int i=1;i<=Q;i++){
		printf("%d %d %d %d\n",1,1,N,random(1,1e9));
	}
}
