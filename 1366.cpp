#include<bits/stdc++.h>
using namespace std;
const int maxn = 500+5;
int y[maxn][maxn],b[maxn][maxn],dp[maxn][maxn];//0往左1往上 最大y跟b礦總和
int row,col;
void dypro(){
	for(int i = 0;i<row;i++){
		for(int j = 0;j<col;j++){
			if(i == 0&&j == 0) continue;
			else if(i == 0) dp[i][j] = max(y[i][j],dp[i][j-1]+b[i][j]);
			else if(j == 0) dp[i][j] = max(dp[i-1][j]+y[i][j],b[i][j]);
			else dp[i][j] = max(dp[i-1][j]+y[i][j],dp[i][j-1]+b[i][j]);
			// max(往左dp[上一row][同一col],往上[前一col][同一row]);
		}
	}
}
int main(int argc, char const *argv[])
{
	while(cin>>row>>col){
		if(row == 0&&col == 0) break;
		memset(dp,0,sizeof(dp));
		memset(y,0,sizeof(y));
		memset(b,0,sizeof(b));
		for(int i = 0;i<row;i++){
			for(int j = 0;j<col;j++){
				scanf("%d",&y[i][j]);//y礦往左
			}
		}
		for(int i = 0;i<row;i++){
			for(int j = 0;j<col;j++){
				scanf("%d",&b[i][j]);//b礦往上
			}
		}
		for(int i = 0;i<row;i++){
			for(int j = 1;j<col;j++){
				y[i][j] += y[i][j-1];//prefix sum 計算他往左(包含他前面都要往左 總合為多少)
			}
		}
		for(int i = 1;i<row;i++){
			for(int j = 0;j<col;j++){
				b[i][j] += b[i-1][j];//prefix sum 計算他往上(包含他前面都要往上 總合為多少)
			}
		}
		dp[0][0] = max(y[0][0],b[0][0]);
		dypro();
		printf("%d\n",dp[row-1][col-1]);
	}
	return 0;
}











//要挖礦要傳送帶 只能直走或橫走不能轉彎
// y礦在西 跟b礦在北
// 要挖到總和最大的y跟b礦
// 最多1000最少0
// 怎麼挖能挖到最多
// 先給的往左