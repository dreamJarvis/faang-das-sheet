#include <bits/stdc++.h>
using namespace std;

int kthSymbol(int n, int k){
	if(k == 1 || n == 1)
		return 0;

	int mid = pow(2, n-2);
	if(k > mid)
		return !kthSymbol(n-1, (k - mid));
	return kthSymbol(n-1, k);
}

int main(){
	int n = 3, k = 4;

	cout << kthSymbol(n, k) << "\n";

	return 0;
} 