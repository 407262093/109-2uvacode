#include<bits/stdc++.h>
using namespace std;
const int maxn = 50;
const int INF = 0x7FFFFFFF;
int arr[maxn];
int dp[maxn][maxn];

int main(){
	int test,cutt,ans,right,minnum;
	while(cin>>test){
		if(test == 0) break;
		ans = test;
		cin>>cutt;
		arr[0] = 0;
		for(int i = 1;i<=cutt;i++){
			cin>>arr[i];
		}
		arr[cutt+1] = test;
		memset(dp,0,sizeof(dp)); 
		for(int i = 1;i<=cutt+1;i++){
			for(int j = 0;j<=cutt+1;j++){//左邊
				right = j+i; minnum = INF;
				for(int k = j+1;k<right;k++){
					if(right > cutt+1) break;
					minnum = min(minnum,dp[j][k]+dp[k][right]);
				}
				if(minnum != INF) dp[j][right] = minnum + (arr[right]-arr[j]);
			}
		}
		printf("The minimum cutting is %d.\n",dp[0][cutt+1]);

	}
	return 0;
}
// 怎麼切成本最低
// 從哪個點切成本都一樣
// 找最小的成本
// 
// 0,2 = 0,1+1,2;
// dp[l][k] = min{dp[l][k],dp[k][r]} + a[r]-a[l]
