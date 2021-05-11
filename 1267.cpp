#include<bits/stdc++.h>
using namespace std;
const int maxn = 1000+5;
vector <int> G[maxn];
vector <int> nodes[maxn];
int n,s,k,whosdad[maxn],c[maxn];
void dfs1(int me,int dad,int dist){//我 /我爸 /我跟我祖宗的距離
	whosdad[me] = dad;//記錄我爸爸是誰
	int nd = G[me].size();
	if(nd == 1 && dist>k) nodes[dist].push_back(me);
	for(int i = 0;i<nd;i++){
		int v = G[me][i];
		if(v != dad) dfs1(v,me,dist+1);
	}
}
void dfs2(int me,int dad,int dist){//建立新伺服器 哪些有受惠
	c[me] = 1;
	int nd = G[me].size();
	for(int i = 0;i<nd;i++){
		int v = G[me][i];
		if(v != dad && dist<k) dfs2(v,me,dist+1);
	}
}
int main(int argc, char const *argv[])
{
	int test,a,b,ans;
	cin>>test;
	while(test--){
		cin>>n>>s>>k;	//node(他是tree) server位置 k表示能支援長度 
		for(int i = 1;i<=n;i++){
			G[i].clear();//G表示誰連接誰
			nodes[i].clear();//我是leaf node
		}
		for(int i = 0;i<n-1;i++){
			cin>>a>>b;
			G[a].push_back(b);
			G[b].push_back(a);
		}
		dfs1(s,-1,0);
		ans = 0;
		memset(c,0,sizeof(c));//紀錄有誰完成了
		cout<<n<<endl;
		for(int dist = (n-1); dist > k;dist--){
			for(int i = 0;i<nodes[dist].size();i++){
				int u = nodes[dist][i];
				if(c[u]){
					continue;
				}
				int v = u;
				for(int j = 0;j<k;j++){//去找我長度k的祖宗
					v = whosdad[v];
				}
				dfs2(v,-1,0);
				ans++;//需要件幾個伺服器
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}