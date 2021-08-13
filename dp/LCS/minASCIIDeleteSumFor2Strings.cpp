#include <bits/stdc++.h>
using namespace std;

int minimumDeleteSum(string s1, string s2) {
	int n = s1.length();
	int m = s2.length();

	vector<vector<int>> dp(n+1, vector<int>(m+1, 0));       

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(s1[i-1] == s2[j-1]){
				dp[i][j] = dp[i-1][j-1] + s1[i-1];
			}else
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
		}
	}
	
	int sum1(0),sum2(0);
	for(auto ch:s1)	sum1 += ch;
	for(auto ch:s2)	sum2 += ch;

	int res = (sum1 - dp[n][m]) + (sum2 - dp[n][m]);

	return res;
}

// Driver function
int main(){
	// string s1 = "sea", s2 = "eat";
	string s1 = "delete", s2 = "leet";

	cout << minimumDeleteSum(s1, s2) << endl;

	return 0;
}