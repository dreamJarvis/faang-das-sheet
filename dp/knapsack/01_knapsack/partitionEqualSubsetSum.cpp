#include <bits/stdc++.h>
using namespace std;

bool helper(vector<int> &nums, int sum, int n, unordered_map<string, bool> &dp){
	string key = to_string(sum) + "_" + to_string(n);

	if(n == -1 || sum < 0)	return false;

	if(dp.count(key)) return dp[key];

	if(sum == 0)	return true;

	dp[key] = helper(nums, sum - nums[n], n-1, dp) || helper(nums, sum, n-1, dp);
	return dp[key];
}

bool canPartitionMemo(vector<int>& nums) {
	int n = nums.size();

	int ts(0);
	for(auto i:nums)
		ts += i;

	if(ts%2)	return false;

	unordered_map<string, bool> dp;
	return helper(nums, ts/2, n-1, dp);
}

bool canPartition(vector<int> &nums){
	int n = nums.size();

	int ts(0);
	for(auto i:nums)
		ts += i;

	if(ts%2)	return false;

	int sum = ts/2;

	bool dp[n+1][sum+1];
	memset(dp, false, sizeof dp);

	for(int i = 0; i <= sum; i++)
		dp[0][i] = false;

	for(int i = 0; i <= n; i++)
		dp[i][0] = true;

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= sum; j++){
			if(j >= nums[i-1]){
				dp[i][j] = dp[i-1][j - nums[i-1]] || dp[i-1][j];
			}else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}

	// for(int i = 0; i <= n; i++){
	// 	for(int j = 0; j <= sum; j++)
	// 		cout << dp[i][j] << " ";
	// 	cout << endl;
	// }

	return dp[n][sum];
}


// Driver function
int main(){
	// vector<int> nums({1, 5, 11, 5});
	vector<int> nums({1, 2, 3, 5});

	cout << canPartition(nums) << endl;

	return 0;
}