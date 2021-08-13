#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> dp;
int helper(string &original, string &reversed, int n, int m){
	string key = to_string(n) + '_' + to_string(m);

	if(n == -1 || m == -1)	return 0;

	if(dp.count(key))	return dp[key];

	char ch1 = original[n];
	char ch2 = reversed[m];

	if(ch1 == ch2)
		return dp[key] = helper(original, reversed, n-1, m-1) + 1;		
	return dp[key] = max(helper(original, reversed, n-1, m), helper(original, reversed, n, m-1));
}

int longestPalindromeSubseq(string s) {
	int n = s.length();
	string reversed = s;
	reverse(reversed.begin(), reversed.end());

	return helper(s, reversed, n-1, n-1);       
}

int longestPalindromeSubseqDP(string s) {
	int n = s.length();
	string reversed = s;
	reverse(reversed.begin(), reversed.end());

	int dp[n+1][n+1];
	memset(dp, 0, sizeof(dp));

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(s[i-1] == reversed[j-1])
				dp[i][j] = dp[i-1][j-1]+1;
			else
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}

	return dp[n][n];
}

// Driver fcuntion
int main(){
	// string str = "bbbab";
	string str = "cbbd";

	// cout << longestPalindromeSubseq(str) << endl;
	cout << longestPalindromeSubseqDP(str) << endl;

	return 0;
}