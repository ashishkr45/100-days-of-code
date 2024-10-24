#include<iostream>
#include<string>
#include<map>
using namespace std;

int main(){
	map<int, string> m;
	m[101] = "ashish";
	m[111] = "dodo";
	m[121] = "bulla";


	cout<<m.count(101)<<endl;
	cout<<m.count(151)<<endl;

	for(auto it: m){
		cout<<it.first<<"\t"<<it.second<<endl;
	}
	return 0;
}