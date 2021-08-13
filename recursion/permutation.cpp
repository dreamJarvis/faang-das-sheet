#include <bits/stdc++.h>
using namespace std;

bool isEqual(vector<int> f1, vector<int> f2){
	for(int i = 0; i < 27; i++){
		if(f1[i] != f2[i])	return false;
	}
	return true;
}

// tc : O(n * 26)
bool checkInclusion(string s1, string s2) {
	int n1 = s1.size();
    int n2 = s2.size();


    if(n1 > n2)	return false;

    if(s1 == s2)	return true;
    
    vector<int> freqs1(27, 0);
    vector<int> tmpFreq(27, 0);

    int s(0), e(0);
    for(; e < n1; e++){
        freqs1[s1[e]-'a']++;
        tmpFreq[s2[e]-'a']++;
    }

    if(isEqual(freqs1, tmpFreq))	return true;

    for(; e < n2; e++, s++){
        tmpFreq[s2[s]-'a']--;
        tmpFreq[s2[e]-'a']++;

        if(isEqual(freqs1, tmpFreq))	return true;
    }

    return false; 
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
