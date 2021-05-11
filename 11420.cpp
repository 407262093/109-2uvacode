#include<bits/stdc++.h>
using namespace std;
const int MAXN = 70;
long long int dp[MAXN][MAXN][2] = {0};// n/s/2  櫃子數/鎖數/最上面lock or unlock = 方法數
int main(int argc, char const *argv[])
{
	int n,s;
	dp[1][1][1] = 1;
	dp[1][0][0] = 1;
	dp[1][1][0] = 0;
	for(int i = 2;i < MAXN;i++){
		for(int j = 0 ; j <= i ; j++){
			dp[i][j][0] = dp[i-1][j][0]+dp[i-1][j+1][1];
			dp[i][j][1] = dp[i-1][j-1][0]+dp[i-1][j-1][1];
		}
	}
	while(cin>>n>>s){
		if(n == -1 &&s == -1) break;
		cout<<dp[n][s][0]+dp[n][s][1]<<endl;
	}
	return 0;
}

// 中間沒隔板
// 上面抽屜打開可以拿下面抽屜
// 第二格索 第一格也要索
// n格 s索
// ans有幾種方法

//n抽屜 s安全 0最上方unlock 1 lock
//dp[N][S][0] = dp[n-1][s][0]+dp[n-1][s+1][1]
//dp[N][S][1] = dp[n-1][s-1][0]+dp[n-1][s-1][1]
//ans = dp[N][S][0]+dp[N][S][1]
//從最上面+櫃子
// 
// 


