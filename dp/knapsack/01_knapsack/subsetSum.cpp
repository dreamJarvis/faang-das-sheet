#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> dp;
int helper(vector<int> &nums, int target, int n){
	string key = to_string(target) + '_' + to_string(n);

	if(n == -1 || target < 0)	return 0;

	if(dp.count(key))	return dp[key];

	if(target == 0)	return 1;

	return helper(nums, target-nums[n], n-1) || helper(nums, target, n-1);
}

int solve(vector<int> &arr, int target){
	int n = arr.size();

	int sum(0);
	for(auto i:arr)
		sum += i;

	if(sum < target)	return 0;
	return helper(arr, target, n-1);
}

int solveDP(vector<int> &arr, int target){
	int n = arr.size();

	int sum(0);
	for(auto i:arr)
		sum += i;

	if(sum < target)	return 0;

	int dp[n+1][target+1];
	memset(dp, 0, sizeof dp);

	for(int i = 0; i <= target; i++)
		dp[0][i] = 0;

	for(int i = 0; i <= n; i++)
		dp[i][0] = 1;

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= target; j++){
			if(j >= arr[i-1]){
				dp[i][j] = dp[i-1][j - arr[i-1]] || dp[i-1][j];
			}else
				dp[i][j] = dp[i-1][j];
		}
	}

	return dp[n][target];
}

int main(){
	// vector<int> A({3, 24, 4, 12, 5, 2});
	// int B = 9;

	vector<int> A({3, 34, 4, 12, 5, 2});
	int B = 30;

	cout << solveDP(A, B) << endl;

	return 0;
}