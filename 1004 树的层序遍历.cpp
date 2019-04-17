#include<iostream>
#include<vector>
using namespace std;
int n,m;
vector<int> node[101];
int deepnum[101];
int maxdeep = -1;
void dfs(int index,int deep){
	if(node[index].size()==0){
		deepnum[deep]++;
		maxdeep = maxdeep>deep?maxdeep:deep;
		return;
	}
	for(int i=0;i<node[index].size();i++){
		dfs(node[index][i],deep+1);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	int id,k,num;
	for(int i=0;i<m;i++){
		scanf("%d%d",&id,&k);
		for(int j=0;j<k;j++){
			scanf("%d",&num);
			node[id].push_back(num);
		}
	}
	dfs(1,0);
	for(int i=0;i<=maxdeep;i++){
		printf("%d",deepnum[i]);
		if(i!=maxdeep) printf(" ");
	}
	
	return 0;
} 
