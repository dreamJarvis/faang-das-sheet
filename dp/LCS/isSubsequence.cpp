#include <bits/stdc++.h>
using namespace std;

bool isSubsequence(string s, string t) {
    int n = s.length();
    int m = t.length();

    int sx(0), sy(0);

    while(sx < n && sy < m){
        if(s[sx] == t[sy]){
            sx++;sy++;
        }else{
            sy++;
        }
    }

    if(sx == n)	return true;
    return false;    
}

int main(){
	string s = "abc";
	string t = "ahbgdc";

	cout << isSubsequence(s, t) << endl;

	return 0;
}