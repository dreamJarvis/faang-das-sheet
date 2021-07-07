#include <bits/stdc++.h>
using namespace std;

void util(stack<int> &st, int tmp){
	if(st.empty()){
		st.push(tmp);
		return;
	}

	int lst = st.top();
	st.pop();
	util(st, tmp);
	st.push(lst);

	return ;
}

void reverseStack(stack<int> &st){
	if(st.empty()) return;

	int tmp = st.top();
	st.pop();
	reverseStack(st);

	util(st, tmp);
	return ;
}

int main(){
	stack<int> st({1, 2, 3, 4, 5, 6});
	stack<int> tmp = st;

	while(!tmp.empty()){
		cout << ' ' << tmp.top() << ' ';
		tmp.pop();
	}
	cout << "\n\n";

	reverseStack(st);

	while(!st.empty()){
		cout << ' ' << st.top() << ' ';
		st.pop();
	}

	return 0;
}