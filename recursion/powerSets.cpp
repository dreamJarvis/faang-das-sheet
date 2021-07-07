#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> subsets(vector<int>& nums) {
	int n = nums.size();
	vector<vector<int>> res = {{}};
	set<vector<int>> uqRes;

	sort(nums.begin(), nums.end());

	for(int i = 0; i < n; i++){
		vector<int> tmp;
		int x = res.size();
		for(int j = 0; j < x; j++){
			tmp = res[j];
			tmp.push_back(nums[i]);
			res.push_back(tmp);		
		}
	}

	return res;
}

int main(){
	vector<int> nums{1, 2, 3};

	for(auto i:subsets(nums)){
		for(auto j: i)
			cout << j << " ";
		cout << "\n";
	}

	return 0;
}