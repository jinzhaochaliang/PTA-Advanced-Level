#include<iostream>
#include<algorithm>
using namespace std;
struct node{
	int id;
	int best;
	int score[4];
	int rank[4];
}stu[2000];
int f = -1;
int exist[1000000];
bool cmp(node a,node b){
	return a.score[f]>b.score[f];
}
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>stu[i].id>>stu[i].score[0]>>stu[i].score[1]>>stu[i].score[2];
		stu[i].score[3] = (stu[i].score[0]+stu[i].score[1]+stu[i].score[2])/3.0+0.5;
	}
	for(f = 0;f<=3;f++){
		sort(stu,stu+n,cmp);
		stu[0].rank[f] = 1;
		for(int i=1;i<n;i++){
			stu[i].rank[f] = i+1;
			if(stu[i].score[f] == stu[i-1].score[f]){
				stu[i].rank[f] = stu[i-1].rank[f];
			}
		}
	}
	for(int i=0;i<n;i++){
		exist[stu[i].id] = i+1;
		stu[i].best = 3;
		int minn = stu[i].rank[3];
		for(int j=0;j<3;j++){
			if(stu[i].rank[j]<minn){
				stu[i].best = j;
				minn = stu[i].rank[j];
			}
		}
	}
	string c[4] = {"C","M","E","A"};
	int id;
	for(int i=0;i<m;i++){
		cin>>id;
		int idd = exist[id];
		if(idd){
			cout<<stu[idd-1].rank[stu[idd-1].best]<<" "<<c[stu[idd-1].best]<<endl;
		}else{
			cout<<"N/A"<<endl;
		}
	}
}
