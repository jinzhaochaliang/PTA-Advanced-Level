#include<iostream>
using namespace std;
int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	string c = to_string(a+b);
	int len = c.length();
	for(int i=0;i<len;i++){
		printf("%c",c[i]);
		if(c[i]=='-'){
			continue;
		}
		if((len-1-i)%3==0&&i!=len-1){
			printf(",");
		}
	}
	
	return 0;
} 
