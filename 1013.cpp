#include<iostream>
using namespace std;
int father[1000];
int u[500000];
int v[500000];
int findfather(int x){
	int a = x;
	while(x!=father[x]){
		x = father[x];
	}
	while(a!=father[a]){
		int z = a;
		a = father[a];
		father[z] = x;
	}
	return x;
}
void Union(int a,int b){
	int fa = findfather(a);
	int fb = findfather(b);
	if(fa!=fb){
		father[fa] = fb;
	}
}
void init(int n){
	for(int i=1;i<=n;i++){
		father[i] = i;
	}
}
int main(){
	int n,m,k,c;
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>u[i]>>v[i];
	}
	for(int i=0;i<k;i++){
		int lost = 0;
		cin>>c;
		init(n);
		for(int i=0;i<m;i++){
			if(u[i]!=c&&v[i]!=c){
				Union(u[i],v[i]);
			}
		}
		for(int i=1;i<=n;i++){
			if(father[i]==i&&i!=c){
				lost++;
			}
		}
		printf("%d\n",lost-1);
	}
	
	return 0;
}
