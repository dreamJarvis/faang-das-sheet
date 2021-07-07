#include <bits/stdc++.h>
using namespace std;

// /*
//     l --> no. of left bracket's in our string
//     r --> no. of right bracket's in our string
// */
// void helper(string str, int n, int l, int r, vector<string> &result){
//     if(l < 0 || r < 0)
//         return ;

//     if(l == 0 && r == 0){
//         result.push_back(str);
//         return ;
//     }

//     if(l > 0){
//         helper(str+'(', n, l-1, r, result);
//     }

    
//     this line means, that we should have more open brackets then the close ones,
//     in our string, at any given time, in order to generate vaid parentheses string

//     if we dont have open brackets, then we cannot include close brackets yet
    
//     if(r > l){
//         helper(str+')', n, l, r-1, result);
//     }
// }

// vector<string> generateParenthesis(int n) {
//     vector<string> result;
//     string str = "";

//     helper(str, n, n, n, result);
//     return result;
// }

void util(string ans, int ob, int cb, vector<string> &results, int n){
    if(ob > n || cb > n)    return;
    
    if(ans.length() == 2*n){
        results.push_back(ans);
        return;
    }

    if(ob < n){
        util(ans+"(", ob+1, cb, results, n);
    }

    if(ob > cb){
        util(ans+")", ob, cb+1, results, n);
    }

    return;
}

vector<string> generateParenthesis(int n) {
    vector<string> results;
    string ans = "";

    util("(", 1, 0, results, n);

    return results;     
}

int main(){
	int n = 3;

	for(auto i:generateParenthesis(n))
		cout << i << "\n";

	return 0;
}