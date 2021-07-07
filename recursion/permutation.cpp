#include <bits/stdc++.h>
using namespace std;

// bool checkInclusion(string s1, string s2) {
// 	int n1 = s1.length();
// 	int n2 = s2.length();

// 	vector<int> map(27, 0);
// 	for(auto &i:s1)
// 		map[i-'a']++;

// 	for(int i = 0; i < n2; i++){
// 		if(map[s2[i]-'a'] > 0 && i+n1 <= n2){
// 			vector<int> tmp = map;
// 			for(int j = i; j < i+n1; j++){
// 				tmp[s2[j]-'a']--;
// 			}

// 			int k = 0;
// 			for(; k < 27; k++){
// 				if(tmp[k] != 0){
// 					break;
// 				}
// 			}

// 			if(k == 27)	return true;
// 		}		
// 	}

// 	return false;
// }

// using KMP search algo
bool checkInclusion(string s1, string s2) {
	        
}

int main(){
	string s1 = "ab";
	string s2 = "eidbaooo";

	// string s1 = "adc";
	// string s2 = "dcda";

	// string s1 = "hello";
	// string s2 = "ooolleoooleh";

	cout << checkInclusion(s1, s2) << endl;

	return 0;
}

/*
"hello"
"ooolleoooleh"

"adc"
"dcda"
*/ 