#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int now = 0;
	int num = 0;
	int cost = 0;
	while(n--){
		cin>>num;
		if(num>now){
			cost += 6*(num-now)+5;
		}else{
			cost += 4*(now-num)+5;
		}
		now = num;
	}
	cout<<cost;
} 
