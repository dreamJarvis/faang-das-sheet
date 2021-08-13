#include <bits/stdc++.h>
using namespace std;

int helper(string &str, int i, int j, unordered_map<string, int> &dp){
    string key = to_string(i) + "_" + to_string(j);

    if(i == -1 || j == -1) return 0;

    if(dp.count(key))   return dp[key];

    int maxLen(0);
    if(str[i] == str[j] && i != j){
        maxLen = 1 + helper(str, i-1, j-1, dp);
    }

    return dp[key] = max(
        maxLen,
        max(
            helper(str, i, j-1, dp),
            helper(str, i-1, j, dp)
        )      
    );
}

int LongestRepeatingSubsequenceMemo(string str){
    int n = str.length();
    unordered_map<string, int> dp;
    return helper(str, n-1, n-1, dp);
}

int LongestRepeatingSubsequence(string str){
    int n = str.length();

    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    int maxLen(1);

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(str[i-1] == str[j-1] && i != j){
                dp[i][j] = dp[i-1][j-1] + 1;
            }else{
                dp[i][j] = max(
                            dp[i-1][j-1],
                            max( dp[i-1][j], dp[i][j-1] )
                        );
            }
            maxLen = max(maxLen, dp[i][j]);    
        }
    }

    return dp[n][n];
}

// Driver function
int main(){
    // string str = "axxxy";
    // string str = "AABEBCDD";
    // string str = "aab";
    string str = "agcsorvauz";

	cout << LongestRepeatingSubsequence(str) << endl;

	return 0;
}