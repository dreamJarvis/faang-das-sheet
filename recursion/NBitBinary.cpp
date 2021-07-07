#include <bits/stdc++.h>
using namespace std;

void util(string ans, int n, int count0, int count1, vector<string> &result){
	if(count0 + count1 == n){
		result.push_back(ans);
		return;
	}

	if(count1 <= n){
		util(ans+"1", n, count0, count1+1, result);
	}

	if(count0 < count1){
		util(ans+"0", n, count0+1, count1, result);
	}

	return;
}

vector<string> NBitBinary(int N){
	vector<string> result;
	util("", N, 0, 0, result);

	return result;
}

int main(){
	int n = 3;;

	for(auto i:NBitBinary(n)){
		for(auto j: i)
			cout << j << " ";
		cout << "\n";
	}

	return 0;
}