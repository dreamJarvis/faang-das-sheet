#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> dp;

int helper(string word1, string word2, int n, int m){
	string key = to_string(n) + '_' + to_string(m);

	if(n == -1)	return m+1;
	if(m == -1)	return n+1;

	if(dp.count(key))	return dp[key];

	if(word1[n] == word2[m]){
		return dp[key] = helper(word1, word2, n-1, m-1);
	}

	int insert = helper(word1, word2, n, m-1);
	int del = helper(word1, word2, n-1, m);
	int replace = helper(word1, word2, n-1, m-1);

	return dp[key] = 1 + min(insert, min(del, replace));
}

int minDistance(string word1, string word2) {
	int n = word1.length();
	int m = word2.length();

	return helper(word1, word2, n-1, m-1);
}

int minDistanceDP(string word1, string word2){
	int n = word1.length();
	int m = word2.length();

	int dp[n+1][m+1];
	memset(dp, 0, sizeof(dp));

	for(int i = 0; i <= n; i++)
		dp[i][0] = i;

	for(int i = 0; i <= m; i++)
		dp[0][i] = i;

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(word1[i-1] == word2[j-1])
				dp[i][j] = dp[i-1][j-1];
			else{
				dp[i][j] = 1 + min(
						dp[i-1][j],
						min(
							dp[i-1][j-1],
							dp[i][j-1]
						)
					);
			}
		}
	}
	

	return dp[n][m];
}

// Driver function
int main(){
	string s1 = "horse";
	string s2 = "ros";

	// string s1 = "intention";
	// string s2 = "execution";

	// string s1 = "a";
	// string s2 = "b";

	// cout << minDistance(s1, s2) << endl;
	cout << minDistanceDP(s1, s2) << endl;

	return 0;
}