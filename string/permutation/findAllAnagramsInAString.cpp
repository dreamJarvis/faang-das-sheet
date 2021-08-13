#include <bits/stdc++.h>
using namespace std;

bool isEqual(int freq1[], int freq2[]){
	for(int i = 0; i < 27; i++)
		if(freq2[i] != freq1[i])	
			return false;
	return true;
}

vector<int> findAnagrams(string s, string p) {
	int n1 = s.length();
	int n2 = p.length();

	vector<int> result;

	int pFreq[27] = {0};
	int tmpFreq[27] = {0};

	int st(0), e(0);
	for(; e < n2; e++){
		pFreq[p[e]-'a']++;
		tmpFreq[s[e]-'a']++;
	}

	for(; e < n1; e++,st++){
		if(isEqual(pFreq, tmpFreq)){
			result.push_back(st);
		}

		tmpFreq[s[st]-'a']--;
		tmpFreq[s[e]-'a']++;
	}

	if(isEqual(pFreq, tmpFreq)){
		result.push_back(st);
	}

	return result;
}

int main(){
	string s = "cbaebabacd", p = "abc";
	// string s = "abab", p = "ab";

	for(auto i:findAnagrams(s, p))
		cout << i << ", ";
	cout << endl;

	return 0;
}