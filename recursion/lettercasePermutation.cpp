#include <bits/stdc++.h>
using namespace std;

void util(string str, int idx, vector<string> &res){
	if(idx == str.length()){
		res.push_back(str);
		return ;
	}

	char ch = str[idx];

	str[idx] = islower(str[idx]) ? toupper(str[idx]) : tolower(str[idx]);
	util(str, idx+1, res);

	if(isalpha(ch)){
		str[idx] = ch;
		util(str, idx+1, res);
	}
}

vector<string> letterCasePermutation(string s) {
	vector<string> res;

	util(s, 0, res);

	return res;
}

int main(){
	string str = "a1b2";

	for(auto i:letterCasePermutation(str))
		cout << i << "\n";

	return 0;
}