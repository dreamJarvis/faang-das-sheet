#include <bits/stdc++.h>
using namespace std;

string longestPalindrome(string str){
	int n = str.length();

	int dp[n][n];
	memset(dp, false, sizeof(dp));

	int start = 0;
	int maxLen = 1;

	// every single charectar is a palindrome
	for(int i = 0; i < n; i++){
		dp[i][i] = true;
	}

	// check for every length 2 palindrome
	for(int i = 0; i < n-1; i++){
		if(str[i] == str[i+1]){
			dp[i][i+1] = true;
			start = i; 
			maxLen = 2;
		}
	}

	// checking for palindromes of length >= 3
	for(int k = 3; k <= n; k++){
		for(int i = 0; i < n-k+1; i++){
			int j = i + k - 1;
  
			if(dp[i+1][j-1] && str[i] == str[j]){
				dp[i][j] = true;

				if(k > maxLen){
					maxLen = k;
					start = i;
				}
			}
		}
	}

	return str.substr(start, maxLen);
}

// Driver funtion
int main(){
	// string s = "babad";
	// string s = "cbbd";
	string s = "aacabdkacaa";

	cout << longestPalindrome(s) << endl;

	return 0;
}