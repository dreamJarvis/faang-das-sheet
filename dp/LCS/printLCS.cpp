#include <bits/stdc++.h>
using namespace std;

string longestCommonSubsequence(string text1, string text2) {
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

	string lcs="";

	int i = n, j = m;
	while(i > 0 && j > 0){
		if(text1[i-1] == text2[j-1]){
			lcs += text1[i-1];
			i--;j--;
		}
		else if(dp[i-1][j]  > dp[i][j-1])
			i--;
		else
			j--;
	}

	reverse(lcs.begin(), lcs.end());
	return lcs;
}

string longestCommonSubsequenceII(string str1, string str2){
	int n = str1.length();
	int m = str2.length();

	vector<vector<string>> dp(n+1, vector<string>(m+1, ""));

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(str1[i-1] == str2[j-1])
				dp[i][j] = dp[i-1][j-1] + str1[i-1];
			else
				dp[i][j] = dp[i-1][j].length() > dp[i][j-1].length() ? dp[i-1][j] : dp[i][j-1];
		}
	}

	return dp[n][m];
}


// Driver function
int main(){
	// string text1 = "yby";
	// string text2 = "bl";

	// string text1 = "abcde";
	// string text2 = "ace";

	string text1 = "abc";
	string text2 = "abc";

	// cout << longestCommonSubsequence(text1, text2) << endl;
	cout << longestCommonSubsequence(text1, text2) << endl;

	return 0;
}