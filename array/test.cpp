#include <bits/stdc++.h>
using namespace std;

void solve(){
	long long n;
	cin >> n;

	long long sum(0), tmp(0);
	for(int i=0;i<n-1;i++){
		cin >> tmp;
		sum += tmp;
	}

	long long naturalSum = n*(n+1)/2;
	long long missingNum = abs(naturalSum - sum);

	cout << missingNum << '\n';

	return;
}

// Driver function 
int main(){
	// int tc;
	// cin >> tc;

	// for(int i = 0; i < tc; i++){
		solve();
	// }

	return 0;
}