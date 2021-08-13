#include <bits/stdc++.h>
using namespace std;

bool helper(vector<int>& nums, int n, int target, int sum, int k, vector<bool> &visited){
	if(k == 1)	return true;
	
	if(n < 0 || sum < 0)	return false;

	if(sum == 0)
		return helper(nums, nums.size()-1, target, target, k-1, visited);

	bool flag;
	if(nums[n] > sum || visited[n])
		return helper(nums, n-1, target, sum, k, visited);
	else{
		visited[n] = true;
		flag = helper(nums, n-1, target, sum-nums[n], k, visited);

		visited[n] = false;
		flag = flag || helper(nums, n-1, target, sum, k, visited);
	}

	return flag;
}

bool canPartitionKSubsets(vector<int>& nums, int k) {
	int n = nums.size();
	int sum(0);

	for(auto i:nums)
		sum += i;

	if(sum%k)	return false;

	int target = sum/k;
	sort(nums.begin(), nums.end());			  // why ??
	vector<bool> visited(nums.size(), false);
	return helper(nums, n, target, target, k, visited);
}	

int main(){
	// vector<int> nums({4,3,2,3,5,2,1});
	// int k = 4;

	vector<int> nums({1, 2, 3, 4});
	int k = 3;

	cout << canPartitionKSubsets(nums, k) << endl;

	return 0;
}