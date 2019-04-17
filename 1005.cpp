#include<iostream>
using namespace std;
int main(){
	string num;
	string s[10] = {
	"zero","one","two","three","four","five","six","seven","eight","nine"
	};
	cin>>num;
	int count = 0;
	for(int i=0;i<num.length();i++){
		count += num[i] - '0';
	}
	string str = to_string(count);
	cout<<s[str[0]-'0'];
	for(int i=1;i<str.length();i++){
		cout<<" "<<s[str[i]-'0'];
	}
	return 0;
}
