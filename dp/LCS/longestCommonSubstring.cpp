#include <bits/stdc++.h>
using namespace std;

int helper(string str1, string str2, int n, int m, unordered_map<string, int> &dp){
	string key = to_string(n) + "_" + to_string(m);

	if(n == -1 || m == -1)	return 0;

	if(dp.count(key))	return dp[key];

	char ch1 = str1[n];
	char ch2 = str2[m];

	int maxLen(0);

	if(ch1 == ch2){
		int i(n), j(m);
		while(i >= 0 && j >= 0 && str1[i] == str2[j]){
			i--;j--;
		}
		int dist = abs(n-i);

		// cout << i <<", " << n << endl;

		// return longestCommonSubstr(str1, str2, i, j) + dist;
		maxLen = max(maxLen ,dist);
	}

	maxLen = max(
			max(
					helper(str1, str2, n-1, m, dp),
					helper(str1, str2, n, m-1, dp)
				), 
			maxLen
		);

	return dp[key] = maxLen;
}

int longestCommonSubstr(string str1, string str2, int n, int m){
	unordered_map<string, int> dp;
	return helper(str1, str2, n-1, m-1, dp);
}

int longestCommonSubstrDP(string str1, string str2, int n, int m){
	int dp[n+1][m+1];
	memset(dp, 0, sizeof(dp));

	int result(0);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(str1[i-1] == str2[j-1]){
				dp[i][j] = dp[i-1][j-1] + 1;
				result = max(result, dp[i][j]);
			}else{
				dp[i][j] = 0;
			}
		}
	}

	return result;
}

int main(){
	// string s1 = "ABCDGH";
	// string s2 = "ACDGHR";

	// string s1 = "ABC";
	// string s2 = "ACB";

	string s1 = "abc";
	string s2 = "abcd";

	// cout << longestCommonSubstr(s1, s2, s1.length(), s2.length()) << endl;
	cout << longestCommonSubstrDP(s1, s2, s1.length(), s2.length()) << endl;

	return 0;
}