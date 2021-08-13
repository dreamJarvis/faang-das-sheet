#include <bits/stdc++.h>
using namespace std;

int util(vector<int>& nums, int totalSum, int target, int n, int currSum, unordered_map<string, int> &dp){
	string key = to_string(n) + '_' + to_string(currSum);
	if(n == -1){
		if((totalSum - 2*currSum) == target)	return 1;
		return 0;
	}

	if(dp.count(key))	return dp[key];

	if(totalSum - currSum < target)	return util(nums, totalSum, target, n-1, currSum, dp);

	dp[key] = (
			util(nums, totalSum, target, n-1, currSum+nums[n], dp) +
			util(nums, totalSum, target, n-1, currSum, dp)
		);

	return dp[key];
}

int findTargetSumWays(vector<int>& nums, int target) {
	int n = nums.size()-1;
	int sum(0);

	for(auto i:nums)
		sum += i;

	unordered_map<string, int> dp;
	return util(nums, sum, target, n, 0, dp);
}

int findTargetSumWaysDP(vector<int>& nums, int target) {
	int n = nums.size();
	int sum(0), countOfZeroes(0);

	for(auto i:nums){
		sum += i;
		if(i == 0) countOfZeroes++;
	}

	if(target > sum)	return 0;
	if((target+sum)%2 !=0)	return 0;

	int s = (target+sum)/2;

	int dp[n+1][s+1];
	memset(dp, 0, sizeof dp);

	for(int i = 0; i <= n; i++)
		dp[i][0] = 1;

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= s; j++){
			if(nums[i-1] && j >= nums[i-1])
				dp[i][j] = dp[i-1][j-nums[i-1]] + dp[i-1][j];
			else
				dp[i][j] = dp[i-1][j];
		}
	}

	return pow(2, countOfZeroes)*dp[n][s];
}

int main(){
	// vector<int> nums({1, 1, 1, 1, 1});
	// int target = 3;

	vector<int> nums({0,0,0,0,0,0,0,0,1});
	int target = 1;

	// vector<int> nums({1});
	// int target = 1;

	cout << findTargetSumWays(nums, target) << endl;
	cout << findTargetSumWaysDP(nums, target) << endl;

	return 0;
}
/*
[0,0,0,0,0,0,0,0,1]
1
*/ 