#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> dp;

int helper(vector<int>& days, vector<int>& costs, int idx, int sum){
	string key = to_string(idx) + '_' + to_string(sum);

	if(idx >= days.size())	return 0;

	if(dp.count(key))	return dp[key];

	if(sum > days[idx])	return helper(days, costs, idx+1, sum);

	int ans = INT_MAX;
	
	ans = min(ans, costs[0] + helper(days, costs, idx, sum=days[idx]+1));
	ans = min(ans, costs[1] + helper(days, costs, idx, sum=days[idx]+7));
	ans = min(ans, costs[2] + helper(days, costs, idx, sum=days[idx]+30));

	return dp[key] = ans;
}

int mincostTickets(vector<int>& days, vector<int>& costs) {
	int n = days.size();
	return helper(days, costs, 0, 0);       
}


// 1-d DP
int mincostTicketsDP(vector<int>& days, vector<int>& costs){
	int n = days.size();
	int dp[366];
	memset(dp, 0, sizeof(dp));

	for(auto &day:days)
		dp[day] = costs[0];

	for(int i = 1; i <= days[n-1]; i++){
		if(!dp[i]){
			dp[i] = dp[i-1];
		}else{
			dp[i] = dp[i-1] + costs[0];

			int j = max(0, i-7);
			dp[i] = min(dp[i], dp[j] + costs[1]);

			j = max(0, j-30);
			dp[i] = min(dp[i], dp[j] + costs[2]);
		}
	}

	return dp[days[n-1]];
}

// Driver function
int main(){
	vector<int> days({1, 4, 6, 7, 8, 20});
	vector<int> costs({2, 7, 15});

	// vector<int> days({1,2,3,4,5,6,7,8,9,10,30,31});
	// vector<int> costs({2, 7, 15});

	// cout << mincostTickets(days, costs) << endl;
	cout << mincostTicketsDP(days, costs) << endl;

	return 0;
}