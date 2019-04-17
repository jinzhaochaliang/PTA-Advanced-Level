#include<iostream>
using namespace std;
int main(){
	
	int k1,k2,n;
	float a[1001] = {0};
	float num;
	
	scanf("%d",&k1);
	for(int i=0;i<k1;i++){
		scanf("%d%f",&n,&num);
		a[n] += num;
	}
	scanf("%d",&k2);
	for(int i=0;i<k2;i++){
		scanf("%d%f",&n,&num);
		a[n] += num;
	}
	
	int count = 0;
	for(int i=1000;i>=0;i--){
		if(a[i]!=0.0) count++;
	}
	printf("%d",count);
	for(int i=1000;i>=0;i--){
		if(a[i]==0.0) continue;
		printf(" %d %.1f",i,a[i]);
	}
	
	return 0;
} 
