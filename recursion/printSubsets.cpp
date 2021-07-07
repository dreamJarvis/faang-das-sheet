#include <bits/stdc++.h>
using namespace std;

void util(string str, string result){
	if(str.length() == 0){
		reverse(result.begin(), result.end());
		cout << result << "\n";
		return;
	}

	int len = str.length();
	string restOfString = str.substr(0, len-1);
	char ch = str[len-1];

	util(restOfString, result+ch);
	util(restOfString, result);

	return;
}

void printSubsets(string str){
	if(str.length() < 1)	return;

	util(str, "");
}

int main(){
	string str = "abc";

	printSubsets(str);

	return 0;
}