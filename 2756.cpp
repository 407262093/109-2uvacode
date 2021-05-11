#include<bits/stdc++.h>
using namespace std;

int main(){
	int test,cas,num,ans;
	cin>>test;
	while(test--){
		cin>>cas;
		num = cas/2;
		if(cas%2){
			ans = num*(num-1)/2 + num*(num+1)/2;
		}
		else{
			ans = num*(num-1);
		}
		cout<<ans<<endl;
	}
}
// 做左便做右


