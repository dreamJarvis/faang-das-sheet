#include <bits/stdc++.h>
using namespace std;

void insert(stack<int> &st, int lstEle){
	if(st.empty() || st.top() >= lstEle){
		st.push(lstEle);
		return;
	}

	int tmp = st.top();
	st.pop();
	insert(st, lstEle);
	st.push(tmp);

	return;
}

void sortStk(stack<int> &st){
	if(st.size() == 1)
		return;

	int lastEle = st.top();
	st.pop();

	sortStk(st);
	insert(st, lastEle);

	return;
}

int main(){
	stack<int> st({12, 3, 7, 6, 4, 5, 9});

	sortStk(st);

	while(!st.empty()){
		cout << ' ' << st.top() ;
		st.pop();
	}

	return 0;
}