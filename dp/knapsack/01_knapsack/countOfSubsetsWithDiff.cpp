#include <bits/stdc++.h>
using namespace std;

int countDiff(vector<int> &arr, int diff, int totalSum, int sum, int n, unordered_map<string, int> &dp){
	string key = to_string(n) + '_' + to_string(sum);
	if(n == -1){
		if(abs(totalSum - 2*sum) == diff)	return 1;
		return 0;
	}

	if(dp.count(key))	return dp[key];

	if(sum+arr[n] > totalSum/2)	return countDiff(arr, diff, totalSum, sum, n-1, dp);

	dp[key] = (
			countDiff(arr, diff, totalSum, sum+arr[n], n-1, dp) + 
			countDiff(arr, diff, totalSum, sum, n-1, dp)
		);

	return dp[key];
}

int countNumberOfDiff(vector<int> &arr, int diff){
	int n = arr.size();

	int sum(0);
	for(auto i:arr)
		sum += i;

	unordered_map<string, int> dp;
	return countDiff(arr, diff, sum, 0, n-1, dp);
}

int countNumberOfDiffDP(vector<int> &arr, int diff){
	int n = arr.size();

	int sum = 0;
	for(auto i:arr)
		sum += i;

	int midSum = sum/2+1;
	int dp[n+1][midSum+1];
	memset(dp, 0, sizeof dp);

	for(int i = 0; i <= n; i++)
		dp[i][0] = 1;

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= midSum; j++){
			if(j >= arr[i-1]){
				dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
			}else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}

	int countDiff(0);
	for(int i = 0; i <= midSum; i++){
		if(dp[n][i] && ((sum - 2*i) == diff)){
			countDiff += dp[n][i];
		}
	}

	return countDiff;
}

int main(){
	vector<int> A({1, 1, 2, 3});
	int diff = 1;

	// vector<int> A({1, 6, 11, 5});
	// vector<int> A({20, 19, 18, 20, 16});
	// vector<int> A({5 ,6 ,6 ,5 ,7 ,4 ,7 ,6});
	// vector<int> A({11, 18, 24, 18, 18});

	cout << countNumberOfDiff(A, diff) <<endl;
	cout << countNumberOfDiffDP(A, diff) <<endl;

	return 0;
}