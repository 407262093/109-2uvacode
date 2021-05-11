#include<bits/stdc++.h>
using namespace std;
const int N = 100000+5;
int leng,wei;
int ri[N],le[N],block[N],ans[N],zeron[N],arr[100][N];//都是以盒子紀錄 ans除外
void findrl(int ti,int count){//ti表示第幾個row //count表示幾個盒子
	int now = 0,zeroti = 0;//zeroti有幾個空格(第幾個)//now表示現在在哪個col
	for(int i = 0;i<count;i++){//往左移
		if(block[i] == 0){
			zeron[zeroti] = i;//第幾個block是0
			le[now] = 0;
			zeroti++;
			now++;
		}
		else{
			for(int j = 0; j<block[i];j++){
				if(zeroti < block[i] - j){//
					le[now] = N;
					now++;
				}
				else{
					le[now] = i - zeron[zeroti - (block[i] - j)] - (block[i] - j) +1; //我要移幾個盒子
					//第i個blcok - zeron 空的在第幾個blcok - 中間i~zeron會有0的狀況(多扣) + 1補回來
					//推的方式 block為單位推
					now++;
				}
			}
		}
	}
	zeroti = 0;
	now = wei-1;
	for(int i = count-1;i>=0;i--){//往右移
		if(block[i] == 0){
			zeron[zeroti] = i;
			ri[now] = 0;
			zeroti++;
			now--;
		}
		else{
			for(int j = 0 ;j<block[i];j++){
				if(zeroti < block[i] - j){
					ri[now] = N;
					now--;
				}
				else{
					ri[now] = zeron[zeroti - (block[i] - j)] - i - (block[i] - j) +1;
					now--;
				}
			}
		}
	}
	for(int i = 0;i<wei;i++){
		arr[ti][i] = min(le[i],ri[i]);
	}
}

int main(int argc, char const *argv[])
{
	int test,count;
	int minload,tmp,loadnum;
	cin>>test;
	while(test--){
		minload = N;
		cin>>leng>>wei;
		for(int i = 0;i<leng;i++){
			cin>>count;
			for(int j = 0;j<count;j++){
				cin>>block[j];
			}
			findrl(i,count);
			// for(int j = 0;j<wei;j++){
			// 	cout<<arr[i][j]<<" ";
			// }
			// cout<<endl;
		}
		for(int i = 0;i<leng;i++){
			minload += arr[i][0];
		}
		loadnum = 1;
		for(int j = 1;j<wei;j++){
			tmp = 0;
			for(int i = 0;i<leng;i++){
				tmp += arr[i][j];
			}
			if(minload > tmp){
				minload = tmp;
				loadnum = 1;
				ans[loadnum-1] = j;
			}
			else if(minload == tmp){
				loadnum++;
				ans[loadnum-1] = j;
			} 
		}
		cout<<minload<<endl;
		cout<<ans[0];
		for(int i = 1;i<loadnum;i++){
			cout<<" "<<ans[i];
		}
		cout<<endl;
	}
	return 0;
}
//移動最少次 有可能出現的通道
// arr設到global 讓他在func的時候就先找移動方式
// 錯誤 block2 空格1 兩個都變不能移動
