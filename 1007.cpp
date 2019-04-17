#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int num[10010];
	int left = 0,right = n-1,templeft = 0;
	int temp = -1;
	int sum = 0;
	for(int i=0;i<n;i++){
		cin>>num[i];
		sum += num[i];
		if(sum<0){
			templeft = i+1;
			sum = 0;
		}else if(sum>temp){
			temp = sum;
			left = templeft;
			right = i;
		}
	}
	if(temp<0){
		temp = 0;
	}
	cout<<temp<<" "<<num[left]<<" "<<num[right];
	
	return 0;
}
