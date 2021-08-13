#include <bits/stdc++.h>
using namespace std;

int helper(vector<int> &nums, int totalSum, int n, int currSum, unordered_map<string, int> &dp){
	string key = to_string(n) + '_' + to_string(currSum);
	if(n == -1){
		return abs( abs(totalSum-currSum) - currSum);
	}

	if(dp.count(key))	return dp[key];

	if((totalSum - currSum) < currSum)	
		return helper(nums, totalSum, n-1, currSum, dp);

	dp[key] = min(
			helper(nums, totalSum, n-1, currSum+nums[n], dp),
			helper(nums, totalSum, n-1, currSum, dp)
		);

	return dp[key];
}

int minDifference(vector<int> &arr)  { 
	int n = arr.size();

	if(n == 1)	return arr[0];
	if(n == 2) 	return abs(arr[0] - arr[1]);

	int sum = 0;
	for(auto i:arr)
		sum += i;

	unordered_map<string, int> dp;
	return helper(arr, sum, n, 0, dp);
}

// Tc: O(n^2)
int minDifferenceDP(vector<int> &arr){
	int n = arr.size();
	
	if(n == 1)	return arr[0];
	if(n == 2) 	return abs(arr[0] - arr[1]);

	int sum = 0;
	for(auto i:arr)
		sum += i;

	int midSum = sum/2+1;
	bool dp[n+1][midSum+1];
	memset(dp, false, sizeof dp);

	for(int i = 0; i <= n; i++)
		dp[i][0] = true;

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= midSum; j++){
			if(j >= arr[i-1]){
				dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
			}else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}

	int minSumDiff(INT_MAX);
	for(int i = 0; i <= midSum; i++){
		if(dp[n][i]){
			minSumDiff = min(minSumDiff, abs(sum - 2*i));
		}
	}

	return minSumDiff;
}

int main(){
	vector<int> A({1, 6, 11, 5});
	// vector<int> A({20, 19, 18, 20, 16});
	// vector<int> A({5 ,6 ,6 ,5 ,7 ,4 ,7 ,6});
	// vector<int> A({11, 18, 24, 18, 18});

	cout << minDifferenceDP(A) << endl;

	return 0;
}