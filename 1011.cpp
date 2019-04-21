#include<iostream>
using namespace std;
int main(){
	float w;
	string s[3]={"W","T","L"};
	float profit = 1.0;
	for(int i=0;i<3;i++){
		int temp = 0;
		float maxn = 0;
		for(int j=0;j<3;j++){
			cin>>w;
			if(maxn<w){
				maxn = w;
				temp = j;
			}
		}
		profit *= maxn;
		cout<<s[temp]<<" "; 
	}
	printf("%.2f",(profit*0.65-1)*2);
}
