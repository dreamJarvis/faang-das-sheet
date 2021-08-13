#include <bits/stdc++.h>
using namespace std;

int prec(char c) {
	if(c == '^')
		return 3;
	else if(c == '/' || c=='*')
		return 2;
	else if(c == '+' || c == '-')
		return 1;
	else
		return -1;
}

int evaluatePostfix(string exp){
	int n = exp.length();

	unordered_map<char, bool> op;
	op['+'] = true;
	op['-'] = true;
	op['*'] = true;
	op['/'] = true;

	stack<int> st;
	int result(0);

	for(int i = 0; i < n; i++){
		if(exp[i] >= 48 && exp[i] <= 57){
			string num="";
			while(i < n && (exp[i] >= 48 && exp[i] <= 57))	num += exp[i++];
			
			int currNum(0);
			stringstream ss(num);
			ss >> currNum;

			st.push(currNum);
		}
		else if(op.count(exp[i])){
			int a = st.top();
			st.pop();

			int b = st.top();
			st.pop();

			switch(exp[i]){
				case '*' : st.push(a*b); break;
				case '/' : st.push(b/a); break;
				case '+' : st.push(a+b); break;
				case '-' : st.push(b-a); break;
			}
		}
	}

	return st.top();	
}

int infixToPostfix(string exp){
	int n = exp.length();

	unordered_map<char, bool> op;
	op['+'] = true;
	op['-'] = true;
	op['*'] = true;
	op['/'] = true;
	op['('] = true;
	op[')'] = true;

	stack<char> st;
	string postFixExp = "";

	for(int i = 0; i < n; i++){
		if(!op.count(exp[i])){
			string num="";
			while(i < n && (exp[i] == 48)) {i++; cout << i << endl;}
			while(i < n && (exp[i] >= 48 && exp[i] <= 57))	num += exp[i++];
			i--;

			cout << num << endl;

			postFixExp += num;
			postFixExp += " ";
		}
		else if(exp[i] == ')'){
			while(!st.empty() && st.top() != '('){
				postFixExp += st.top();
				postFixExp += " ";
				st.pop();
			}
			st.pop();
		}
		else{
			// if an operator with higher precedence is already present, 
			// than pop out all the lower precedence operators
			while(!st.empty() && prec(st.top()) > prec(exp[i])){
				postFixExp += st.top();
				postFixExp += " ";
				st.pop();
			}

			st.push(exp[i]);
		}
	}

	while(!st.empty() && st.top() != '('){
		postFixExp += st.top();
		postFixExp += " ";
		st.pop();
	}

	cout << postFixExp << endl;
	postFixExp.erase(postFixExp.end()-1);
	return evaluatePostfix(postFixExp);
}

int main(){
	// string str = "2+3*2-5*3";
	string str = "1 05 *";

	cout << infixToPostfix(str) << endl;	

	return 0;
}