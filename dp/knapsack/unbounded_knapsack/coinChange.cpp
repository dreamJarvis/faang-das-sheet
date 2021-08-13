#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> dp;

int helper(vector<int>& coins, int amount, int n){
	string key = to_string(n) + '_' + to_string(amount);

	if(n < 0 || amount < 0)	return INT_MAX - 1;

	if(amount == 0)
		return 0;

	if(dp.count(key))	return dp[key];

	if(amount < coins[n])	return helper(coins, amount, n-1);

	return dp[key] = min(	
			helper(coins, amount-coins[n], n) + 1,
			helper(coins, amount, n-1)
		);
}

int coinChange(vector<int>& coins, int amount) {
	int n = coins.size();

	int ans = helper(coins, amount, n-1);
	return ans == (INT_MAX-1) ? -1 : ans;       
}

int coinChangeDP(vector<int>& coins, int amount) {
	int n = coins.size();

	if(amount < 0)	return -1;
       
    vector<vector<int>> dp(n+1, vector<int>(amount+1, 1009));

    for(int i = 0; i <= n; i++)
    	dp[i][0] = 0;

    for(int i = 1; i <= n; i++){
    	for(int j = 1; j <= amount; j++){
    		if(j  >= coins[i-1]){
    			dp[i][j] = min(
    					dp[i][j - coins[i-1]] + 1,
    					dp[i-1][j]
    				);
    		}else
    			dp[i][j] = dp[i-1][j];
    	}
    }

    // for(int i = 0; i <= n; i++){
    // 	for(int j = 0; j <= amount; j++)
    // 		cout << dp[i][j] << " ";
    // 	cout << endl;
    // }

    return dp[n][amount] > 1000 ? -1 : dp[n][amount];
}

// Driver function
int main(){
	// vector<int> coins({1, 2, 5});
	// int amount = 11;

	// vector<int> coins({2});
	// int amount = -1;

	vector<int> coins({1});
	int amount = 0;

	// cout << coinChange(coins, amount) << endl;
	cout << coinChangeDP(coins, amount) << endl;

	return 0;
}