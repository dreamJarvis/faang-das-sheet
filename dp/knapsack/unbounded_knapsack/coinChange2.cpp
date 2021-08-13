#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> dp;
int helper(vector<int> &coins, int amount, int n){
	string key = to_string(amount) + '_' + to_string(n);

	if(n == -1)	return 0;

	if(dp.count(key))	return dp[key];

	if(amount == 0) return 1;

	if(amount < coins[n])	return helper(coins, amount, n-1);

	dp[key] = helper(coins, amount-coins[n], n) + helper(coins, amount, n-1);

	return dp[key];
}

int change(int amount, vector<int>& coins) {
	int n = coins.size();
	return helper(coins, amount, n-1);
}

int changeDP(int amount, vector<int>& coins) {
	int n = coins.size();

	int dp[n+1][amount+1];
	memset(dp, 0, sizeof(dp));

	for(int i = 0; i <= n; i++)
		dp[i][0] = 1;

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= amount; j++){
			if(j >= coins[i-1]){
				dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j];
			}else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}

	return dp[n][amount];
}

// driver function
int main(){
	vector<int> coins({1, 2, 5});
	int amount = 5;

	// vector<int> coins({10});
	// int amount = 10;

	// cout << change(amount, coins) << endl;
	cout << changeDP(amount, coins) << endl;

	return 0;
}