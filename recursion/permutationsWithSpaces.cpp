#include <bits/stdc++.h>
using namespace std;

void util(string str, string ans, int idx, int n, vector<string> &res){
	if(idx == n){
		res.push_back(ans);
		return;
	}

	char ch = str[idx];
	string tmp = ans + " " + ch;
	string tmp2 = ans + ch;

	util(str, tmp2, idx+1, n, res);
	util(str, tmp, idx+1, n, res);
}

vector<string> permutation(string S){
	vector<string> res;
	int n = S.length();
	string ans = S.substr(0,1);
	util(S, ans, 1, n, res);

	return res;
}

int main(){
	string str = "abc";

	for(auto i:permutation(str))
		cout << i << "\n";
	cout << "\n";

	return 0;
}