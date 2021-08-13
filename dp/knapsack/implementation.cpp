#include <bits/stdc++.h>
using namespace std;

int helper(int N, int W, int val[], int wt[]){
	if(W == 0 || N < 0)	return 0;

	if(wt[N] > W)	return helper(N-1, W, val, wt);

	return max(
			helper(N, W-wt[N], val, wt) + val[N],
			helper(N-1, W, val, wt)
		);
}

int knapSack(int N, int W, int val[], int wt[]){
	return helper(N-1, W, val, wt);
}

int knapSackDP(int N, int W, int val[], int wt[]){
	int dp[N+1][W+1];
	memset(dp, 0, sizeof dp);

	for(int i = 0; i <= N; i++)
		dp[i][0] = 0;
	for(int i = 0; i <= W; i++)
		dp[0][i] = 0;

	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= W; j++){
			if(j >= wt[i-1]){
				dp[i][j] = max(dp[i][j-wt[i-1]]+val[i-1], dp[i-1][j]);;
			}else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}

	return dp[N][W];
}

// Driver function
int main(){
	int N = 4, W = 8;
	int val[] = {1, 4, 5, 7};
	int wt[] = {1, 3, 4, 5};

	// int N = 2, W = 3;
	// int val[] = {1, 1};
	// int wt[] = {2, 1};

	// cout << knapSack(N, W, val, wt) << endl;
	cout << knapSackDP(N, W, val, wt) << endl;

	return 0;
}