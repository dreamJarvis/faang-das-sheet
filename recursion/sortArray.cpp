#include <bits/stdc++.h>
using namespace std;
 
void insert(vector<int> &arr, int tmp){
	if(arr.size() == 0 || arr[arr.size()-1] <= tmp){
		arr.push_back(tmp);
		return;
	}

	int val = arr[arr.size()-1];
	arr.pop_back();
	insert(arr, tmp);
	arr.push_back(val);
}

void sortArr(vector<int> &arr){
	if(arr.size() == 1)	return;

	int temp = arr[arr.size()-1];
	arr.pop_back();
	sortArr(arr);

	insert(arr, temp);
}

// Driver function
int main(){
	vector<int> arr({12, 3, 7, 6, 4, 5, 9});

	sortArr(arr);

	for(auto i:arr)
		cout << i << " ";

	return 0;
}