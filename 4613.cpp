#include<bits/stdc++.h>
using namespace std;
const int maxn = 200+5;
long long int dp[maxn][maxn][2] = {0};
long long int abegin[maxn],bbegin[maxn],atime[maxn],btime[maxn],acars,bcars;
void init(){
	for(int i = 0;i<acars;i++){
		for(int j = 0;j<bcars;j++){
			dp[i][j][0] = dp[i][j][1] = 1000000000;
		}
	}
}
void dypro(){
	long long int t1,t2;//t1:出發時間 t2:到達時間
	dp[0][0][1] = 0;
	dp[0][0][0] = 0;
	for(int i = 0;i<acars;i++){
		for(int j = 0;j<bcars;j++){
			t1 = dp[i][j][0];t2 = 0;//最後是a端通過的車 現在換換b端通過
			for(int k = j+1 ;k<bcars;k++){//k表示B車多一個
				t1 = max(t1,bbegin[k]);
				cout<<"turn B "<<i<<" "<<k<<" "<<t1<<" ";
				t2 = max(t2,t1+btime[k]);
				cout<<t2<<" ";
				dp[i][k][1] = min(dp[i][k][1],t2);
				cout<<dp[i][k][1]<<endl;
				t1+=10;
				t2+=10;
			}
			t1 = dp[i][j][1],t2 = 0;//同上 相反
			for(int k = i+1;k<acars;k++){
				t1 = max(t1,abegin[k]);
				cout<<"turn A "<<i<<" "<<k<<" "<<t1<<" ";
				t2 = max(t2,t1+atime[k]);
				cout<<t2<<" ";
				dp[k][j][0] = min(dp[k][j][0],t2);
				cout<<dp[k][j][0]<<endl;
				t1+=10;
				t2+=10;
			}
		}
	}
	cout<<min(dp[acars-1][bcars-1][1],dp[acars-1][bcars-1][0])<<endl;
}
int main(int argc, char const *argv[])
{
	int test,cas;
	char space;
	cin>>test;
	while(test--){
		acars = 1;
		bcars = 1;
		cin>>cas;
		for(int i = 0;i<cas;i++){
			cin>>space;
			if(space == 'A'){
				cin>>abegin[acars]>>atime[acars];
				acars++;
			}
			else{
				cin>>bbegin[bcars]>>btime[bcars];
				bcars++;
			}
		}
		init();
		dypro();
	}

	return 0;
}
//不可有不同方向
//同方向不可追撞(10秒)
//最後一部到達時間為多少
//A走 or B走 
//到的時間 出發的時間
// dp[i][j][0] = 最短時間
// i輛 a端車
// j輛 b端  0/1 a最後或b最後