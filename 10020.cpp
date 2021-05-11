#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int test,M,cas1,cas2,num,left = 0,right;
	int arr[100000+5];
	cin>>test;
	for(int k = 1;k<=test;k++){
		cin>>M;
		left = num = 0;
		pair<int,int>x[100000+5];
		memset(arr,0,sizeof(arr));
		while(cin>>cas1>>cas2){
			if(cas1 ==0 &&cas2 == 0) break;
			x[num] = make_pair(cas1,cas2);
			num++;//表示輸入幾條線
		}
		sort(x,x+num);
		// cout<<"num = "<<num<<endl;
		int edge = 0,i = 0;
		while(left<M){
			right = left;
			while(i < num && left >= x[i].first){
				if(right < x[i].second){
					right = x[i].second;
					arr[edge] = i;//紀錄我要的線是第幾條線
					// cout<<"right = "<<right<<endl;
				}
				i++;
			}
			if(right == left) break;//表示沒更新過right的值(沒找到)
			left = right;
			edge++;
		}
		// cout<<"left = "<<left<<endl;
		if(left<M){
			cout<<"0\n";
		}
		else{
			cout<<edge<<endl;
			for(int j = 0;j<edge;j++){
				cout<<x[arr[j]].first<<" "<<x[arr[j]].second<<endl;
			}
		}
		if(k != test) cout<<endl;//empty line
	}
	return 0;
}
// 0~m最少幾個線段
// 沒有連起來填0
// 有連起來線段數跟哪個線段
// 