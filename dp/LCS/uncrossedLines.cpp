#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> dp;
int helper(vector<int>& nums1, vector<int>& nums2, int n, int m){
	string key = to_string(n) + '_' + to_string(m);

	if(n <= -1 || m <= -1)	return 0;

	if(dp.count(key)) return dp[key];

	if(nums1[n] == nums2[m])	return dp[key] = 1 + helper(nums1, nums2, n-1,  m-1);

	return dp[key] = max(
		helper(nums1, nums2, n-1, m),
		helper(nums1, nums2, n, m-1)
	);
}

int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
	int n = nums1.size();
	int m = nums2.size();

	return helper(nums1, nums2, n-1, m-1);       
}


int maxUncrossedLinesDP(vector<int>& nums1, vector<int>& nums2) {
	int n = nums1.size();
	int m = nums2.size();


	int dp[n+1][m+1];
	memset(dp, 0, sizeof(dp));

	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= m; j++){
			if(!i || !j)	dp[i][j] = 0;
			else if(nums1[i-1] == nums2[j-1])	dp[i][j] = 1 + dp[i-1][j-1];
			else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}

	return dp[n][m];
}

// Dricer function
int main(){
	vector<int> nums1({1,4,2});
	vector<int> nums2({1,2,4});

	// vector<int> nums1({2,5,1,2,5});
	// vector<int> nums2({10,5,2,1,5,2});

	// vector<int> nums1({1,3,7,1,7,5});
	// vector<int> nums2({1,9,2,5,1});

	cout << maxUncrossedLines(nums1, nums2) << endl; 
	cout << maxUncrossedLinesDP(nums1, nums2) << endl; 

	return 0;
}