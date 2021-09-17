#include<bits/stdc++.h>
#define ll long long
const int N=500000,Q=500000;
using namespace std;
int l,r,len,num,k;
int book[5000005],st[500005],ed[500005];
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
	srand(time(NULL)*rand());
	const double ALPHA = 0.1;
	for(register int i=1;i<=Q;i++){
		int p=rand()%4;
		if(p==1){
			int v=random(1,len);
			printf("1 %d %d %d\n",st[v],ed[v],book[v]);
			continue;
		}
		l=random(1,N);
		srand(rand());
		r=random(l,min(N,l+int(ALPHA * (double)N)));
		while(l==0||r==0){
			l=rand()*rand()%N;
			srand(rand());
			r=rand()*rand()%N;
		}
		if(l>r)swap(l,r);
		srand(rand()*2);
		int u=random(1,len);
		int o=(rand()%3==1)?book[u]:random(1,1e9);
		int op=rand()%2+1;
		printf("%d %d %d %d\n",op,l,r,o);
		if(op==2){
			book[++len]=o;
			st[len]=l;
			ed[len]=r;
		}
	}
}
