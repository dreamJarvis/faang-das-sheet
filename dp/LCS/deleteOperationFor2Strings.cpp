#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> dp;
int lcs(string &word1, string &word2, int n, int m){
	string key = to_string(n) + '_' + to_string(m);

	if(n == -1 || m == -1)	return 0;

	if(dp.count(key))	return dp[key];

	char ch1 = word1[n];
	char ch2 = word2[m];
	
	if(ch1 == ch2)
		return dp[key] = lcs(word1, word2, n-1, m-1) + 1;
	return dp[key] = max(lcs(word1, word2, n-1, m), lcs(word1, word2, n, m-1));
}

int minDistance(string word1, string word2) {
	int n = word1.length();
	int m = word2.length();       

	int commonDist = lcs(word1, word2, n-1, m-1);
	int minDist = abs(n-commonDist) + abs(m-commonDist);

	return minDist;
}

int minDistanceDP(string word1, string word2) {
	int n = word1.length();
	int m = word2.length();       

	int dp[n+1][m+1];
	memset(dp, 0, sizeof(dp));

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(word1[i-1] == word2[j-1])
				dp[i][j] = dp[i-1][j-1] + 1;
			else
				dp[i][j] = max( dp[i-1][j], dp[i][j-1]);
		}
	}

	int minDist = abs(n-dp[n][m]) + abs(m-dp[n][m]);

	return minDist;
}

// Driver funtion
int main(){
	// string word1 = "sea";
	// string word2 = "eat";

	string word1 = "leetcode";
	string word2 = "etco";

	// cout << minDistance(word1, word2) << endl;
	cout << minDistanceDP(word1, word2) << endl;

	return 0;
}