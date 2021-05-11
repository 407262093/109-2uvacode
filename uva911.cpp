#include<bits/stdc++.h>
using namespace std;
const int maxn = 305;
int arr[maxn];
long long int ans;
int main(){
	int test,num,fu;
	while(cin>>test){
		ans = 1;
		memset(arr,0,sizeof(arr));
		for(int i = 2;i<=test;i++){
			arr[i] = 1;
		}
		cin>>num;
		for(int i = 0;i<num;i++){
			cin>>fu;
			for(int i = 2;i<=fu;i++){
				arr[i]-=1;
			}
		}
		for(int i = 2;i<maxn;i++){
			if(arr[i] == 1) ans*=i;
		}
		for(int i = 2;i<maxn;i++){
			if(arr[i]<0){
				for(int j = 0;j>arr[i];j--){
					ans/=i;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

// n!
//------------		= ans;
// z1!z2!z3!..zk!
// next_permutation(arr)