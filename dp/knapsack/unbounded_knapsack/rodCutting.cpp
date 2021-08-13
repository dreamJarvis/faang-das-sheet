#include <bits/stdc++.h>
using namespace std;

int helper(int dist, vector<int> val, int n, unordered_map<string, int> &dp){
	string key = to_string(dist) + '_' + to_string(n);

	if(dist < 0 || n < 0)	return INT_MIN;
	if(dist == 0)	return 0;
	if(dist < val[n])	return helper(dist, val, n-1, dp);

	if(dp.count(key))	return dp[key];

	dp[key] = max(
			helper(dist-val[n], val, n, dp)+1,
			helper(dist, val, n-1, dp)
		);

	return dp[key];
}

int maximizeTheCuts(int n, int x, int y, int z){
	vector<int> vals({x, y, z});
	unordered_map<string, int> dp;
	return helper(n, vals, 2, dp);
}


int maximizeTheCutsDP(int n, int x, int y, int z){
	int dp[n+1];
	memset(dp, -1, sizeof(dp));

	dp[0] = 0;

	for(int i =	0; i <= n; i++){
		if(dp[i] == -1)	
			continue;

		if(i+x <= n)
			dp[i+x] = max(dp[i+x], dp[i]+1);
		
		if(i+y <= n)
			dp[i+y] = max(dp[i+y], dp[i]+1);
		
		if(i+z <= n)
			dp[i+z] = max(dp[i+z], dp[i]+1);
	}

	return dp[n] == -1 ? 0 : dp[n];
}

// Driver function
int main(){
	// cout << maximizeTheCuts(5, 5, 3, 2) << endl;
	// cout << maximizeTheCuts(4, 2, 1, 1) << endl;
	// cout << maximizeTheCuts(7, 5, 5, 2) << endl;
	// cout << maximizeTheCutsDP(7, 5, 5, 2) << endl;
	// cout << maximizeTheCutsDP(4, 2, 1, 1) << endl;
	// cout << maximizeTheCutsDP(7, 5, 5, 2) << endl;
	cout << maximizeTheCutsDP(100, 23, 15, 50) << endl;

	return 0;
}