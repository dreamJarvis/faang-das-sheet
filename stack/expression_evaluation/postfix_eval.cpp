#include <bits/stdc++.h>
using namespace std;

int evaluatePostfix(string postfixExp){
	int n = postfixExp.length();

	stack<int> st;

	int i(0), sum(0);
	while(i < n){
		string num="";
		while(i < n && (postfixExp[i] >= 48 && postfixExp[i] <= 57))	num += postfixExp[i++];

		int currNum(0);
		stringstream ss(num);
		ss >> currNum;

		if(num.length()){
			st.push(currNum);
		}else if(postfixExp[i] == '*' || postfixExp[i] == '/' || postfixExp[i] == '+' || postfixExp[i] == '-'){
			int a = st.top();
			st.pop();

			int b = st.top();
			st.pop();

			if(postfixExp[i] == '*')	st.push(a*b);
			else if(postfixExp[i] == '/')	st.push(b/a);
			else if(postfixExp[i] == '+')	st.push(a+b);
			else if(postfixExp[i] == '-')	st.push(b-a);
		}

		i++;
	}

	int ans = st.top();
	return ans;
}

// Driver function
int main(){
	// string postfixExp = "2_3_*_5_4_*_+_9_-";
	string postfixExp = "10 5 +";

	cout << evaluatePostfix(postfixExp) << endl;

	return 0;
}