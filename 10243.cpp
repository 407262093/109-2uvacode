#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1000+5;
vector<int> arr[MAXN];
int dp[MAXN][2];//dp[號碼][放or不放]
void dfs(int me,int dad){
	dp[me][0] = dp[me][1] = 0;
	for(int i = 0;i<arr[me].size();i++){
		int v = arr[me][i];
		if(v == dad) continue;
		dfs(v,me);
		dp[me][0] += dp[v][1];
		dp[me][1] += min(dp[v][0],dp[v][1]);
	}
	dp[me][1]++;
}
int main(){
	int test,now,cas,p;
	while(cin>>test){
		if(test == 0) break;
		if(test == 1) {cout<<"1\n"; continue;}
		for(int i = 0;i<MAXN;i++){
			arr[i].clear();
			dp[i][0] = 0;
		}
		for(int n = 1;n<=test;n++){
			cin>>cas;
			for(int i = 0;i<cas;i++){
				cin>>p;
				arr[n].push_back(p);
			}
		}
		dfs(1,-1);//一個點 阿爸不要處理 找阿爸
		for(int i = 1;i<=test;i++){
			cout<<i<<" "<<dp[i][0]<<" "<<dp[i][1]<<endl;
		}
		cout<<min(dp[1][0],dp[1][1])<<endl;
	}
}

//畫廊跟畫廊只會有走道
//畫廊連接成一棵樹
//建逃生 任何一個走道防火至少
//任何一個走道隔壁畫廊有滅火氣之類的
//4個畫廊
//3 幾個 1連234 
//1個 2連1
// ......
// dp = 我放 我不放(滅火器)
// vertax cover => np-complete解不出來
// tree => dp
// d[u] = min vertax cover
// d[u][0/1] = 我這個點選或不選
// =min {
//		1. 我選 = 連接的邊我來處理  = 1 + 我所有小孩的選或不選的最小加總 
//		2. 我不選 = 所有我小孩要選 = 我所有小孩都要選
// }
// ans = min(d[u][0],d[u][1]);
// 


