#include <bits/stdc++.h>
using namespace std;
const int maxn = 4000+5;
const int w_maxn = 300000+5;
const int mod = 20071027;
int val[w_maxn],sz,ch[maxn][26];//ch[編號][a~z] = 他到...A~Z的編號 val[編號] = 字長度(如果沒有則為0)
int dp[maxn];//dp[第幾個字] = 他有幾種方式可以組成
string st,str;
vector <int> al;

void init(){
	sz = 1;//val對照表 從1號開始
	memset(ch[0],0,sizeof(ch[0]));
	memset(dp,0,sizeof(dp));
}
void findp(int beg,int len){
	int Nob = 0,cid;//表示幾號 我是第一個表示0號
	for(int i = 0;i<len;i++){
		cid = st[beg+i]-'a';//cid 表示A->0 B->1依此類推
		if(ch[Nob][cid] == 0) return;//找有沒有這個字(我為第一個字後面有沒有其他包含其他字)
		Nob = ch[Nob][cid];
		if(val[Nob]) al.push_back(val[Nob]);//找到有 放進去它的長度
	}
}
void dypro(){
	int N = st.length(); dp[N] = 1;
	for(int i = N-1;i>=0;i--){//從最後面找到最前面
		al.clear();
		findp(i,N-i);
		for(int j = 0;j<al.size();j++){
			dp[i] = (dp[i] + dp[i+al[j]]) % mod;
		}
	}
}
int main(int argc, char const *argv[])
{
	int cas = 0,test,Nob,cid;
	while(cin>>st){
		cas++;
		init();
		cin>>test;
		for(int i = 0;i<test;i++){//trip
			cin>>str;
			Nob = 0;//表示幾號 我是第一個表示0號
			for(int i = 0;i<str.length();i++){
				cid = str[i]-'a';//cid 表示A->0 B->1依此類推
				if(ch[Nob][cid] == 0){
					ch[Nob][cid] = sz;
					memset(ch[sz],0,sizeof(ch[sz]));//新的 將編號對照的a~z都設0
					val[sz] = 0;
					sz++;
				}
				Nob = ch[Nob][cid];//找到字串到str[i]的所屬編號
			}
			val[Nob] =	str.length();//表示有幾個字
		}
		dypro();
		printf("Case %d: %d\n",cas,dp[0]);
	}
	return 0;
}

// 數字不超過20071027 %20071027
// 單字都小寫 不超過100字
// 4000不同的字
// 有幾種方法湊出上面的單字
// 
// sol
// dp[i] = 後墜到我這邊有幾種方法 ans = dp[o]
// word set{} (不會)
// a 在word set裡面 a+bcd,ab+cd => dp[0] = dp[0]+dp[1] , dp[0] = dp[0]+dp[2]	
// dp[i] = dp[i]+dp[i+length(k)]
// trip ch[接在幾號後面(0表示自己)][a~z] = 幾號 ,val[幾號] = 長度or不存在
// 