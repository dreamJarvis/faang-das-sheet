#include <bits/stdc++.h>
using namespace std;


// memoisation 
int helper(vector<int> &nums, int target, int n, int sum, unordered_map<string, int> &dp){
	string key = to_string(n) + to_string(sum);

	if(sum == 0)	return 1;
	if(n <= -1 || sum < 0)	return 0;

	if(dp.count(key))	return dp[key];

	if(nums[n] > sum)	return helper(nums, target, n-1, sum, dp);

	dp[key]	= helper(nums, target, n-1, sum-nums[n], dp) + 
				helper(nums, target, n-1, sum, dp);

	return dp[key];
}

int countOfsubsets(vector<int> &nums, int target){
	int n = nums.size();

	unordered_map<string, int> dp;
	return helper(nums, target, n-1, target, dp);
}

// top down approach
int countOfsubsetsDP(vector<int> &nums, int target){
	int n = nums.size();

	int dp[n+1][target+1];
	memset(dp, -1, sizeof dp);

	for(int i = 0; i <= n; i++)
		dp[0][i] = 1;

	for(int i = 0; i <= target; i++)
		dp[i][0] = 0;

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= target; j++){
			if(j >= nums[i-1]){
				dp[i][j] = dp[i-1][j - nums[j-1]] + dp[i-1][j];
			}else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}

	return dp[n][target];
}

int main(){
	// vector<int> nums({4,3,2,3,5,2,1});
	// int k = 4;

	// vector<int> nums({1, 2, 3, 4});
	// int k = 3;

	vector<int> nums({2, 3, 5, 6, 8, 10});
	int k =  10;

	cout << countOfsubsets(nums, k) << endl;

	return 0;
}