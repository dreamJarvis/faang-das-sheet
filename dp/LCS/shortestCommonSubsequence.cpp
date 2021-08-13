#include <bits/stdc++.h>
using namespace std;

string lcs(string& A, string& B) {
    int n = A.size(), m = B.size();
    vector<vector<string>> dp(n + 1, vector<string>(m + 1, ""));

    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            if (A[i] == B[j])
                dp[i + 1][j + 1] = dp[i][j] + A[i];
            else
                dp[i + 1][j + 1] = (dp[i + 1][j].size() > dp[i][j + 1].size()) ?  dp[i + 1][j] : dp[i][j + 1];
    	}
    }
    
    return dp[n][m];
}

string shortestCommonSupersequence(string str1, string str2) {
	int n(str1.length()), m(str2.length());

	int i(0), j(0);
	string res = "";

	for(char c : lcs(str1, str2)){
		while(i < n && str1[i] != c)
			res += str1[i++];

		while(j < m && str2[j] != c)
			res += str2[j++];

		res += c; i++; j++;		// skip the lcs charecter & add it only once
	}

	res = res + str1.substr(i) + str2.substr(j);

	return res;
}

// Driver function
int main(){
	// string str1 = "AGGTAB";
	// string str2 = "GXTXAYB";

	string str1 = "abac";
	string str2 = "cab";

	cout << shortestCommonSupersequence(str1, str2) << endl;

	return 0;
}