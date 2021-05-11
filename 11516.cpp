#include<bits/stdc++.h>
using namespace std;
const int maxn = 100000+5;
int ap,n;
int house[maxn];
int apnum;
void check(int m){
	apnum = 1;
	int num = house[0]+m;
	for(int i = 1;i<n;i++){
		if(num<house[i]){
			apnum++;
			num = house[i]+m;
		}
	}
}
int main(){
	int test,lo,hi,mid;
	cin>>test;
	while(test--){
		cin>>ap>>n;
		for(int i = 0;i<n;i++){
			scanf("%d",&house[i]);
		}
		sort(house,house+n);
		lo = 0;hi = 2*(house[n-1]-house[0])+1;//ap範圍 +-長度
		while(hi-lo>1){			
			mid = (lo+hi)/2;
			check(mid*2);//ap範圍 +-長度
			if(apnum<=ap) hi = mid;
			else lo = mid;
		}
		lo*=10;
		hi*=10;//要計算到小數第一位
		for(int i = 0;i<n;i++){
			house[i]*=10;
		}
		while(hi-lo>1){
			mid = (lo+hi)/2;
			check(mid*2);//ap範圍 +-長度
			if(apnum<=ap) hi = mid;
			else lo = mid;
		}
		printf("%d.%d\n",hi/10,hi%10);
	}
	return 0;
}

// wifi幫忙架基地台
// 2,3 ap多少,幾家住戶		1,3,10 門牌碼
//ans = 房子離最近的ap多少

// 二分法
// 第一次整數運算確認長度
// 
// 
// 