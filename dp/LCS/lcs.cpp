#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> dp;
int helper(string &text1, string &text2, int n, int m){
	string key = to_string(n) + "_" + to_string(m);

	if(n == -1 || m == -1)	return 0;

	if(dp.count(key))	return dp[key];

	char ch1 = text1[n];
	char ch2 = text2[m];

	if(ch1 == ch2)
		return dp[key] = helper(text1, text2, n-1, m-1) + 1;		
	return dp[key] = max(helper(text1, text2, n-1, m), helper(text1, text2, n, m-1));
}

int longestCommonSubsequence(string text1, string text2) {
	int n = text1.length();
	int m = text2.length();

	return helper(text1, text2, n-1, m-1);
}

int longestCommonSubsequenceDP(string text1, string text2) {
	int n = text1.length();
	int m = text2.length();

	int dp[n+1][m+1];
	memset(dp, 0, sizeof(dp));

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(text1[i-1] == text2[j-1])
				dp[i][j] = dp[i-1][j-1] + 1;
			else
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}

	return dp[n][m];
}

// Driver function
int main(){
	string text1 = "yby";
	string text2 = "bl";

	// string text1 = "abcde";
	// string text2 = "ace";

	// string text1 = "abc";
	// string text2 = "abc";

	// cout << longestCommonSubsequence(text1, text2) << endl;
	cout << longestCommonSubsequenceDP(text1, text2) << endl;

	return 0;
}