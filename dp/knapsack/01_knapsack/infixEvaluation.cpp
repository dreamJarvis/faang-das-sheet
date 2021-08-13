/* C++ implementation to convert
infix expression to postfix*/

#include<bits/stdc++.h>
using namespace std;

//Function to return precedence of operators
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

// The main function to convert infix expression
//to postfix expression
string infixToPostfix(string s) {

	stack<char> st; //For stack operations, we are using C++ built in stack
	string result;

	for(int i = 0; i < s.length(); i++) {
		char c = s[i];

		// If the scanned character is
		// an operand, add it to output string.
		if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
			result += c;

		// If the scanned character is an
		// ‘(‘, push it to the stack.
		else if(c == '(')
			st.push('(');

		// If the scanned character is an ‘)’,
		// pop and to output string from the stack
		// until an ‘(‘ is encountered.
		else if(c == ')') {
			while(st.top() != '(')
			{
				result += st.top();
				st.pop();
			}
			st.pop();
		}

		//If an operator is scanned
		else {
			while(!st.empty() && prec(s[i]) <= prec(st.top())) {
				result += st.top();
				st.pop();
			}
			st.push(c);
		}
	}

	// Pop all the remaining elements from the stack
	while(!st.empty()) {
		result += st.top();
		st.pop();
	}

	return result;
}

int evaluatePostfix(string exp) {
    stack<char> st;      
    for (int i = 0; exp[i]; ++i) { 
        if (isdigit(exp[i])) 
            st.push(exp[i] - '0'); 
        else{ 
            
            int val1 = st.top(); 
 			st.pop();
            int val2 = st.top(); 
            st.pop();
            
            switch (exp[i]) { 
            case '+': st.push(val2 + val1); break; 
            case '-': st.push(val2 - val1); break; 
            case '*': st.push(val2 * val1); break; 
            case '/': st.push(val2/val1); break; 
            } 
        } 
    } 

    int ans = st.top();
    return ans; 
} 

//Driver program to test above functions
int main() {
	string exp = "a+b*(c^d-e)^(f+g*h)-i";
	string result = infixToPostfix(exp);

	cout << evaluatePostfix(result) << endl;

	return 0;
}
