#include<iostream>
#include<cmath>
using namespace std;
bool isprime(int k){
	if(k<=1){
		return false;
	}
	int sqt = sqrt(1.0*k);
	for(int i=2;i<=sqt;i++){
		if(k%i==0){
			return false;
		}
	}
	return true;
}
int main(){
	int n,d;
	int res[100001];
	while(1){
		cin>>n;
		if(n<0) break;
		cin>>d;
		if(!isprime(n)){
			cout<<"No\n";
			continue;
		}
		int index = 0;
		do{
			res[index++] = n%d;
			n /= d;
		} while(n!=0);
		int rev=0,j=0;
		for(int i = index-1;i>=0;i--){
			rev += res[i]*pow(d,j);
			j++;
		}
//		cout<<rev;
		if(isprime(rev)){
			cout<<"Yes\n";
		}else{
			cout<<"No\n";
		}
	}
	return 0;
}
