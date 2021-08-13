#include <bits/stdc++.h>
using namespace std;

int evaluatePrefix(string exp){
	int n = exp.length();

	reverse(exp.begin(), exp.end());
	stack<int> st;

	int i(0), sum(0);
	while(i < n){
		string num="";
		while(i < n && (exp[i] >= 48 && exp[i] <= 57))	num += exp[i++];

		int currNum(0);
		stringstream ss(num);
		ss >> currNum;

		if(num.length()){
			st.push(currNum);
		}else if(exp[i] == '*' || exp[i] == '/' || exp[i] == '+' || exp[i] == '-'){
			int a = st.top();
			st.pop();

			int b = st.top();
			st.pop();

			if(exp[i] == '*')	st.push(a*b);
			else if(exp[i] == '/')	st.push(b/a);
			else if(exp[i] == '+')	st.push(a+b);
			else if(exp[i] == '-')	st.push(b-a);
		}

		i++;
	}

	int ans = st.top();
	return ans;
}

// Driver function
int main(){
	string prefix = "- + * 2 3 * 5 4 9";

	cout << evaluatePrefix(prefix) << endl;

	return 0;
}