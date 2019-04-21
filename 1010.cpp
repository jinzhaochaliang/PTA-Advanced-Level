#include<iostream>
using namespace std;
long long tonum(char c){
	if(c>='0'&&c<='9'){
		return c-'0';
	}
	return c-'a'+10;
}
long long shi(long long radix,string n){
	long long sum=0;
	long long  index = 1;
	for(int i=n.length()-1;i>=0;i--){
		sum += tonum(n[i])*index;
		if(sum<0||index<0){
			return -1;
		}
		index *= radix;
	}
	return sum;
}
long long find(long long n,string n1){
	long long left = 2;
	for(int i=0;i<n1.length();i++){
		left = max(left,tonum(n1[i])+1);
	}
	long long right = n+1;
	while(left<=right){
		long long mid = (left+right)/2;
		long long temp = shi(mid,n1);
		if(temp==-1||temp>n){
			right = mid-1;
		}
		else if(temp==n){
			return mid;
		}else{
			left = mid+1;
		}
	}
	return -1;
}
int main(){
	string n1,n2;
	long long tag,radix;
	cin>>n1>>n2>>tag>>radix;
	long index;
	if(tag==1){
		index = find(shi(radix,n1),n2);
	}else if(tag==2){
		index = find(shi(radix,n2),n1);
	}
	if(index==-1){
		printf("Impossible");
	}else{
		printf("%d",index);
	}
} 
