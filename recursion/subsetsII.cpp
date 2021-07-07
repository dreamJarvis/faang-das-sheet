#include <bits/stdc++.h>
using namespace std;

void util(vector<int> nums, vector<int> subset, vector<vector<int>> &res){
	if(nums.size() == 0){
		res.push_back(subset);
		return;
	}

	vector<int> tmp = subset;
	int currValue = nums[0];	
	
	nums.erase(nums.begin());		
	tmp.push_back(currValue);

	if(res.size() > 1 && tmp == res.back()){
		util(nums, subset, res);
	}else{
		util(nums, tmp, res);
		util(nums, subset, res);
	}

	return;
}

vector<vector<int>> subsetsWithDupRecur(vector<int>& nums) {
    int n = nums.size();
	vector<vector<int>> res;

	sort(nums.begin(), nums.end());

	vector<int> tmp;
	util(nums, tmp, res);

	return res;    
}

/* 
	tc : O(n*m*l) 
	n -> size of nums array
	m -> size of result array
	l -> no. of repetetions
*/
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
   unordered_map<int, int> map;
    for(auto &i:nums)
        map[i]++;

    vector<vector<int>> result;
    result.push_back({});

    for(auto &i:map){
        int n = result.size();
        for(int j = 0; j < n; j++){
            vector<int> temp = result[j];
            for(int k = 0; k < i.second; k++){
                temp.push_back(i.first);
                result.push_back(temp);
            }
        }
    }

    return result; 
}

int main(){
	vector<int> nums{1, 2, 2};

	for(auto i:subsetsWithDup(nums)){
		for(auto j: i)
			cout << j << " ";
		cout << "\n";
	}

	return 0;
}
