#include <bits/stdc++.h>
using namespace std;


void util(stack<int> &st, int midIdx){
	if(midIdx == 1)	{
		st.pop();
		return;
	}

	int tmpEle = st.top();
	st.pop();

	util(st, midIdx-=1);

	st.push(tmpEle);

	return ;
}

void deleteMiddleEle(stack<int> &st){
	int n = st.size();
	int midIdx(0);

	midIdx = n/2;
	if(n%2)
		midIdx = n/2 + 1;
	
	util(st, midIdx);
	return ;
}

int main(){
	stack<int> st({1, 2, 3, 4, 5});

	deleteMiddleEle(st);

	while(!st.empty()){
		cout << ' ' << st.top() << ' ';
		st.pop(); 
	}

	return 0;
}