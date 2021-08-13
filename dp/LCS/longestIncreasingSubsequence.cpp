#include <bits/stdc++.h>
using namespace std;

// memo
// unordered_map<string, int> dp;
// int helper(vector<int>& nums, int prev, int curr){
//     string key = to_string(prev) + "_" + to_string(curr);

//     if(curr == nums.size())	return 0;

//     if(dp.count(key))   return dp[key];

//     int maxLen(0);
//     if(prev == -1 || nums[curr] > nums[prev]){
//         maxLen = 1 + helper(nums, curr, curr+1);
//     }

//     return dp[key] = max(
//     		maxLen,
//             helper(nums, prev, curr+1)
//         );
// }

// int lengthOfLIS(vector<int>& nums) {
//     int n = nums.size();
//     return helper(nums, -1, 0);
// }

int lengthOfLIS(vector<int> &nums){
	int n = nums.size();

	vector<int> dp(n, 1);
	int maxLen(1);
	for(int i=1; i < n; i++){
		for(int j = i; j >= 0; j--){
			if(nums[i] > nums[j])
				dp[i] = max(dp[i], dp[j]+1);
		}
		maxLen = max(maxLen, dp[i]);
	}

	return maxLen;
}

int main(){
	// vector<int> nums({10,9,2,5,3,7,101,18});
	// vector<int> nums({0,1,0,3,2,3});
	// vector<int> nums({7,7,7,7,7,7,7});
    // vector<int> nums({-1, 3, 4, 5, 2, 2, 2, 2});

	cout << lengthOfLIS(nums) << endl;

	return 0;
}