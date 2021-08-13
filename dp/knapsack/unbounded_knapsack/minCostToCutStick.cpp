#include <bits/stdc++.h>
using namespace std;

vector<int> arr;
int dp[109][109];

int solve(int idx, int jdx, int l,int r){
	if(idx < 0 || jdx >= arr.size() || idx > jdx)	return 0;

	if(idx == jdx)	return r-l;

	if(dp[idx][jdx] != -1)	return dp[idx][jdx];

	int ans = INT_MAX;
	for(int i = idx; i <= jdx; i++)
		ans = min(ans, (r-l) + solve(idx, i-1, l, arr[i]) + solve(i+1, jdx, arr[i], r));

	return dp[idx][jdx] = ans;
}

int minCost(int n, vector<int>& cuts) {
   memset(dp, -1, sizeof(dp));
   sort(cuts.begin(), cuts.end());

   arr = cuts;

   return solve(0, cuts.size()-1, 0, n);
}

// Driver function
int main(){
	int n = 7;
	vector<int> cuts({1, 3, 4, 5});

	cout << minCost(n, cuts) << endl;

	return 0;
}