#include <bits/stdc++.h>
using namespace std;

// dutch national flag problem
void sort012(int a[], int n){
	int lo(0), mid(0), high(n-1);

	while(mid <= high){
		switch(a[mid]){
			case 0:
				swap(a[lo++], a[mid++]);
				break;

			case 1:
				mid++;
				break;

			case 2:
				swap(a[mid], a[high--]);
				break;
		}
	}

	return;
}

// Driver function
int main(){
	int a[] = {0, 2, 1, 2, 0, 1, 1, 2};
	int n = sizeof(a)/sizeof(a[0]);

	sort012(a, n);

	for(auto i:a)
		cout << i << " ";

	return 0;
}