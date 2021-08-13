#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;

	int arr[n];
	int unique[1000];
	memset(unique, 0, sizeof(unique));
	int no_of_unique_elements(0);
	
	for(int i = 0; i < n; i++){
		cin >> arr[i];

		if(unique[arr[i]] == 0){
			unique[arr[i]] = 1;
			no_of_unique_elements++;
		}
	}

	if(no_of_unique_elements >= n/2)
		cout << "YES\n";
	else 
		cout << "NO\n";

	return 0;
}