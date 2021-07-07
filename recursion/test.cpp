#include <bits/stdc++.h>
using namespace std;

int main(){
	vector<int> nums{1, 2, 2};

	for(auto i:subsetsWithDup(nums)){
		for(auto j: i)
			cout << j << " ";
		cout << "\n";
	}

	return 0;
}