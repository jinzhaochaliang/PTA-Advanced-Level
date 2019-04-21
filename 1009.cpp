#include<iostream>
using namespace std;
int main(){
	float a[1001] = {0};
	float b[2001] = {0};
	int n,m;
	float num;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>m>>num;
		a[m] = num;
	}
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>m>>num;
		for(int j=0;j<1001;j++){
			b[m+j] += a[j] * num;
		}
	}
	
	int count = 0;
	for(int i=0;i<2001;i++){
		if(b[i]!=0.0) count++;
	}
	cout<<count;
	for(int i=2000;i>=0;i--){
		if(b[i]!=0.0){
			printf(" %d %.1f",i,b[i]);
		}
	}
	
	return 0;
}
