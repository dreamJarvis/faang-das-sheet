#include <bits/stdc++.h>
using namespace std;

int minOperations(string str1, string str2){
	int n = str1.length();
	int m = str2.length();

	// if(n == 0)	return m;
	// if(m == 0)	return n;

	int dp[n+1][m+1];
	memset(dp, 0, sizeof(dp));

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(str1[i-1] == str2[j-1])
				dp[i][j] = dp[i-1][j-1] + 1;
			else
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}

	int res = (n - dp[n][m]) + (m - dp[n][m]); 
	
	return res;
} 

int main(){
	string str1 = "";
	string str2 = "az";

	cout << minOperations(str1, str2) << endl;

	return 0;
}