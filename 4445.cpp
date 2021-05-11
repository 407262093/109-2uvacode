#include <bits/stdc++.h>
using namespace std;
int order[8],test;
double a[8],b[8],L,maxL,fuck;
double greedy(){
	double last = a[order[0]] , target;	
	for(int i = 1;i<test;i++){
		target = last+L;	//預計著陸時間
		if(target > b[order[i]]){	//不在安全範圍內
			return 1;
		}
		last = max(target,a[order[i]]);	//真正著陸時間
	}
	return last - b[order[test-1]];//與最後一架飛機預定降落時間相差值，正簡短負加長time	
}
int main(int argc, char const *argv[])
{
	int cas = 0;
	while(cin>>test){
		cas++;
		if(test == 0) break;
		for(int i = 0;i<test;i++){
			cin>>a[i]>>b[i];
			a[i]*=60; b[i]*=60;//換秒
			order[i] = i;
		}
		maxL = -0.1;
		do{
			double lo = 0,hi = 86400;
			while(fabs(lo-hi)>=1e-3){//誤差值不超過1e-3
				L = (lo+hi)/2;
				fuck = greedy();
				if(fuck<=1e-2) lo = L;
				else hi = L;
			}
			maxL = max(L,maxL);	
		}while(next_permutation(order,order+test));
		maxL = (int)(maxL+0.5);//四捨五入
		printf("Case %d: %d:%0.2d\n",cas,(int)(maxL/60),(int)maxL%60);
	}
	return 0;
}
//飛機著陸時間
// ans = 間隔最大的時間多長
// 報搜->二分搜->greedy
// 
// 
// 
// 
// 
// 
// 



// if(arr[i][j]>arr[k][j]){
// 	tmp = i;
// 	arr[i][0] = arr[k][0]
// 	arr[i][1] = arr[k][1]
// 	arr[k][j] = arr[tmp][j]
// 	arr[k][j+1] = arr[tmp][j+1]
// }