#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define MOD 100000007

// leetcode : 1927. Sum Game
bool sumGame(string num) {
    int n = num.size();

    int leftSum(0), rightSum(0);       
    int leftSpaces(0), rightSpaces(0);
    
    for(int i = 0; i < n/2; i++){
        if(num[i] != '?')
            leftSum += (num[i] - '0');
        else
            leftSpaces++;
    }

    for(int i = n/2; i < n; i++){
        if(num[i] != '?')   
            rightSum += (num[i] - '0');
        else
            rightSpaces++;
    }

    if((leftSpaces + rightSpaces) == 0) return (leftSum != rightSum);

    if((leftSpaces + rightSpaces)%2 == 1)   return true;

    int minCommonSpaces = min(leftSpaces, rightSpaces);
    leftSpaces -= minCommonSpaces;
    rightSpaces -= minCommonSpaces;

    if(leftSpaces > 0){
        if(leftSum > rightSum) return true;

        if( 9*(leftSpaces/2) == abs(rightSum - leftSum))    return false;
        else return true;
    }else{
        if(rightSum > leftSum)   return true;
        if( 9*(rightSpaces/2) == abs(rightSum - leftSum))   return false;
        else return true;
    }

    return true;
}

signed main(){
    string num = "?3295???";
    // string num = "25??";
    // string num = "5023";
    // string num = "9?";

    cout << sumGame(num) << endl;

	return 0;
}