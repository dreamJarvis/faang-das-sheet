#include <bits/stdc++.h>
using namespace std;

int minInsertions(string s) {
	string t = s;
	reverse(t.begin(), t.end());

	int n = s.length();
	vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(s[i-1] == t[j-1])
				dp[i][j] = dp[i-1][j-1] + 1;
			else
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}

	return n-dp[n][n];
}

// Driver function
int main(){
	string s = "zzazz";
	// string s = "mbadm";
	
	// string s = "leetcode";
	// string s = "zjveiiwvc";

	cout << minInsertions(s) << endl;

	return 0;
}