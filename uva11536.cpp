#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000005;
int arr[maxn] = {0};
int num[maxn] = {0};//個數
int leng,ri,le = 0;

int main(int argc, char const *argv[])
{
	int test,N,M,K,cnt,ans,tf;
	scanf("%d",&test);
	for(int cas = 1;cas<=test;cas++){
		scanf("%d",&N);
		scanf("%d",&M);
		scanf("%d",&K);
		ans = maxn;
		le = ri = cnt = 0;
		memset(num,0,sizeof(num));
		arr[0] = 1;arr[1] = 2;arr[2] = 3;
		for(int i = 3;i<N;i++){
			arr[i] = ((arr[i-1]+arr[i-2]+arr[i-3])%M)+1;
		}
		tf = 0;
		while(ri < N){
			if(cnt < K){
				if(arr[ri] <= K){
					if(num[arr[ri]] == 0){
						cnt++;
						if(cnt == K){
							tf = 1;
						}
					}
					num[arr[ri]]++;
				}
				ri++;
			}
			else if(le < ri){
				if(arr[le] <= K){
					num[arr[le]]--;
					if(num[arr[le]] == 0){
						cnt--;
						leng = ri - le;
						ans = min(leng,ans);
					}
				}
				le++;
			}
			printf("right: %d left: %d\n",ri,le);
		}
		if(tf == 1) printf("Case %d: %d\n",cas,ans);
		else printf("Case %d: sequence nai\n", cas);
	}
	
	return 0;
}

