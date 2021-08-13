#include <bits/stdc++.h>
using namespace std;

unordered_map<string, bool> dp;
bool helper(string s, string p, int n, int m){
    string key = to_string(n) + '_' + to_string(m);

    if(n <= -1 && m <= -1)  return true;
    if(n <= -1 && p[m] == '*')  return helper(s, p, n, m-2);
    if(n <= -1 || m <= -1)  return false;

    if(dp.count(key))   return dp[key];

    if(s[n] == p[m]){
        return dp[key] = helper(s, p, n-1, m-1);
    }else{
        if(p[m] == '*'){
            if(s[n] == p[m-1] || p[m-1] == '.'){
                return dp[key] = helper(s, p, n-1, m) || helper(s, p, n, m-2);
            }else{
                return dp[key] = helper(s, p, n, m-2);
            }
        }else if(p[m] == '.'){
            return dp[key] = helper(s, p, n-1, m-1);
        }else
            return dp[key] = false;
    }
}

bool isMatch(string s, string p) {
    int n = s.length();
    int m = p.length();

    return helper(s, p, n-1, m-1);       
}

bool isMatchDP(string s, string p) {
    int n = s.length();
    int m = p.length();

    bool dp[n+1][m+1];
    memset(dp, false, sizeof(dp));

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            if(!i && !j)    dp[i][j] = true;
            else if(!i && p[j-1] == '*')    dp[i][j] = dp[i][j-2];
            else if(!i || !j)   dp[i][j] = false;
            else{
                if(s[i-1] == p[j-1])    dp[i][j] = dp[i-1][j-1];
                else{
                    if(p[j-1] == '*'){
                        if(s[i-1] == p[j-2] || p[j-2] == '.')   
                            dp[i][j] = dp[i-1][j] || dp[i][j-2];
                        else
                            dp[i][j] = dp[i][j-2];
                    }else if(p[j-1] == '.')
                        dp[i][j] = dp[i-1][j-1];
                    else
                        dp[i][j] = false;
                }
            }
        }
    }

    return dp[n][m];
}

// Driver function
int main(){
    // string s = "a";
    // string p = ".*..a";

    // string s = "ab";
    // string p = ".*";

    string s = "aa";
    string p = "*";

    // string s = "aab";
    // string p = "c*a*b";

    // string s = "aaa";
    // string p = "ab*a*c*a";

    // string s = "mississippi";
    // string p = "mis*is*p*.";

    // string s = "mississippi";
    // string p = "mis*is*ip*.";

    cout << isMatchDP(s, p) << endl;

    return 0;
}