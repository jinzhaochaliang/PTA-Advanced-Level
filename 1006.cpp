#include<iostream>
using namespace std;
int main(){
	string minname,maxname;
	int mintime = 24*3600+60*60+60;
	int maxtime = 0;
	
	int n;
	cin>>n;
	int h,m,s,time;
	string name;
	for(int i=0;i<n;i++){
		cin>>name;
		scanf("%d:%d:%d",&h,&m,&s);
		time = h*3600+m*60+s;
		if(time<mintime){
			mintime = time;
			minname = name;
		}
		scanf("%d:%d:%d",&h,&m,&s);
		time = h*3600+m*60+s;
		if(time>maxtime){
			maxtime = time;
			maxname = name;
		}
	}
	
	cout<<minname<<" "<<maxname;
	
	return 0;
}
