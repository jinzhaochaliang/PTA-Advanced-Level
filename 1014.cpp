#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct node{
	int starttime,endtime;
	queue<int> q;
};
int main(){
	int n,m,k,q;
	cin>>n>>m>>k>>q;
	vector<int> time(k+1);
	for(int i=1;i<=k;i++){
		cin>>time[i];
	}
	int count = 1;
	vector<node> window(n+1);
	vector<int> result(k+1);
	vector<bool> sorry(k+1,false);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(count<=k){
				window[j].q.push(time[count]);
				if(window[j].endtime>=540){
					sorry[count] = true;
				}
				window[j].endtime += time[count];
				if(i==1){
					window[j].starttime = window[j].endtime;
				}
				result[count] = window[j].endtime;
				count++;
			}
		}
	}
	while(count<=k){
		int tempmin = window[1].starttime;
		int tempwindow = 1;
		for(int i=2;i<=n;i++){
			if(window[i].starttime<tempmin){
				tempwindow = i;
				tempmin = window[i].starttime;
			}
		}

		window[tempwindow].q.pop();
		window[tempwindow].q.push(time[count]);
		window[tempwindow].starttime += window[tempwindow].q.front();

		if(window[tempwindow].endtime>=540){
			sorry[count] = true;
		}

		window[tempwindow].endtime += time[count];
		result[count] = window[tempwindow].endtime;

		count++; 
	}

	for(int i=1;i<=q;i++){
		int query,minute;
		scanf("%d",&query);
		minute = result[query];
		if(sorry[query] == true){
			printf("Sorry\n");
		}else{
			printf("%02d:%02d\n",(minute+480)/60,(minute+480)%60 );
		}
	}
}
