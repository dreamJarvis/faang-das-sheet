#include <bits/stdc++.h>
using namespace std;

vector<string> phoneMap = {
	"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
};


void util(string digits, string ans, int idx, vector<string> &result){
    if(idx == digits.length()){
        result.push_back(ans);
        return;
    }

    for(auto &ch: phoneMap[digits[idx]-'2']){
    	util(digits, ans+ch, idx+1, result);
    }

    return;
}

vector<string> letterCombinations(string digits) {
    vector<string> result;
    
    if(digits == "")    return result;

    util(digits ,"", 0, result);

    return result;   
}

int main(){
	string digits = "234";

	for(auto i:letterCombinations(digits)){
		for(auto j: i)
			cout << j << " ";
		cout << "\n";
	}

	return 0;
}