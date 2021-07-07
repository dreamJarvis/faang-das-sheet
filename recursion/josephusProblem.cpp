#include <bits/stdc++.h>
using namespace std;

// tc : O(n)
// sc : O(n)
int util(vector<int> &arr, int k, int idx){
	int n = arr.size();
	if(n == 1){
		return arr[0];
	}

	int i = (idx+k)%n;
	arr.erase(arr.begin() + i);

	return util(arr, k, i);
}

int safePos(int n, int k) {
	vector<int> arr(n, 0);
	for(int i = 0; i < n; i++)
		arr[i] = i+1;

	return util(arr, k-1, 0);
}

// tc : O(n)
// sc : O(1)
int safePosII(int n, int k){
	if(n == 1)
		return 1;
	else
		return (safePosII(n-1, k) + k - 1)%n + 1;
}

int main(){
	int n = 2, k = 1;

	cout << safePosII(n, k) << endl;

	return 0;
}