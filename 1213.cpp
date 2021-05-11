#include<bits/stdc++.h>
using namespace std;
const int maxn = 1120+5;
int arr[maxn] = {0};//數字是否為質數
int prime[maxn];//質數
int dp[maxn][15] = {0};//dp[數字][質數幾個加總] = 方法
void init(){
	memset(arr,0,sizeof(arr));//全設為0表示還沒找
	int now = 0;
	for(int i = 2;i<maxn;i++){//找 到1125的所有質數
		if(arr[i] == 0){
			arr[i] = now;
			prime[now] = i;
			now += 1;
			for(int j = i*i;j<maxn;j+=i){//設為1表示他不是質數
				arr[j] = 1;
			}
		}
	}
	dp[0][0] = 1;
	for(int i = 0;i<now;i++){
		for(int n = 1120;n>=prime[i];n--){//從後面那先 怕前面動到
			for(int k = 1;k<15;k++){
				dp[n][k] += dp[n-prime[i]][k-1];
			}
		}
	}
}


int main(int argc, char const *argv[])
{
	int n,k,ans;
	init();
	while(cin>>n>>k){
		if(n == 0&&k == 0) break;
		else if(n == 1 || n == 4) cout<<"0"<<endl;
		else{
			cout<<dp[n][k]<<endl;
		}
	}
	return 0;
}
