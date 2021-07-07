#include <bits/stdc++.h>
using namespace std;

// recursive solutions
void helper(int currPos, int n, int k, vector<int> &tmp, vector<vector<int>> &res){
	if(tmp.size() == k){
		res.push_back(tmp);
		return ;
	}

	for(int i = currPos; i <= n; i++){
		tmp.push_back(i);
		helper(i+1, n, k, tmp, res);
		tmp.pop_back();
	}
}

// recursive solutions
vector<vector<int>> combineRecur(int n, int k) {
	vector<vector<int>> res;
	vector<int> tmp;

	helper(1, n, k, tmp, res);

	return res;
}

// iterative solution
vector<vector<int>> combineIteration(int n, int k) {
	vector<vector<int>> result;

	int i = 0;
	vector<int> p(k, 0);

	while(i >= 0){
		p[i]++;

		if(p[i] > n)	--i;
		else if(i == k - 1) result.push_back(p);
		else {
			++i;
			p[i] = p[i-1];
		}
	}

	return result;
}

// Driver functions
int main(){
	int n = 4, k = 2;

	// for(auto i:combineRecur(n, k)){
	// 	for(auto j: i)
	// 		cout << j << " ";
	// 	cout << "\n";
	// }

	for(auto i:combineIteration(n, k)){
		for(auto j: i)
			cout << j << " ";
		cout << "\n";
	}

	return 0;
}