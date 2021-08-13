#include <bits/stdc++.h>
using namespace std;

int knapSack(int W, int wt[], int val[], int n){
	if(n == -1 || W == 0){
		return 0; 
	}

	if(W < wt[n]){
		return knapSack(W, wt, val, n-1);
	}

	int inc = knapSack(W - wt[n], wt, val, n-1) + val[n];
	int exc = knapSack(W, wt, val, n-1);

	return max(inc, exc);
}

int helper(int W, int wt[], int val[], int n, unordered_map<string, int> &dp){
	string key = to_string(W) + "_" + to_string(n);

	if(n == -1 || W == 0) return 0;

	if(dp.count(key))	return dp[key];

	if(W < wt[n])
		return knapSack(W, wt, val, n-1);
	else{
		dp[key] = max(
			knapSack(W - wt[n], wt, val, n-1) + val[n],
			knapSack(W, wt, val, n-1)
		);
	}

	return dp[key];
}

int knapSackMemo(int W, int wt[], int val[], int n){
	unordered_map<string, int> dp;
	return helper(W, wt, val, n, dp);
}

int knapSackDP(int W, int wt[], int val[], int n){
	int dp[n+1][W+1];
	memset(dp, -1, sizeof dp);

	for(int i = 0; i <= W; i++){
		dp[0][i] = 0;
	}

	for(int i = 0; i <= n; i++){
		dp[i][0] = 0;
	}

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= W; j++){
			if(j >= wt[i-1]){
				dp[i][j] = max(
						dp[i-1][j - wt[i-1]] + val[i-1],
						dp[i-1][j]
					);
			}else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}

	return dp[n][W];
}

// Driver function
int main(){
	int n = 3, w = 4;
	int values[] = {1, 2, 3};
	int weight[] = {4, 5, 1};

	// int n = 3, w = 3;
	// int values[] = {1, 2, 3};
	// int weight[] = {4, 5, 6};

	cout << knapSackDP(w, weight, values, n) << endl;
	// knapSackDP(w, weight, values, n);

	return 0;
}