#include <bits/stdc++.h>
using namespace std;

#define MAX 1e5

int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
    unordered_set<int> restricted(forbidden.begin(), forbidden.end());
    vector<vector<int>> visited(2, vector<int>(MAX));

    // visited[0][i] --> we have arrived from left to the i'th place, os the movement was forward
    // visited[1][i] --> we have arrived from right to the i'th place, os the movement was backward
    //  0 --> forward movement, 1 --> backward movement

    // given in the questiuon, we cannot travel backwards consecutively
    queue<pair<int, bool>> position;
    position.push({0, false});

    // the 0'th position is visited, as we start from that position
    visited[0][0] = 1;
    visited[1][0] = 1;
    int ans(0);

    while(!position.empty()){
        int len = position.size();
        while(len > 0){
            len--;

            int curr = position.front().first;
            int flag = position.front().second;

            if(curr == x)   return ans;

            int forward = curr + a;
            int backward = curr - b;

            if(forward < MAX && !visited[0][forward] && !restricted.count(forward)){
                visited[0][forward] = 1;
                position.push({forward, 0});
            }

            if(backward >= 0 && !visited[1][backward] && !restricted.count(backward) && !flag){
                visited[1][backward] = 1;
                position.push({backward, 1});
            }

            position.pop();
        }

        ans++;
    }

    return -1;
}

// Driver function  
int main(){
    // vector<int> forbidden({14,4,18,1,15});
    // int a(3), b(15), x(9);

    // vector<int> forbidden({8,3,16,6,12,20});
    // int a(15), b(13), x(11);

    vector<int> forbidden({1,6,2,14,5,17,4});
    int a(16), b(9), x(7);

    cout << minimumJumps(forbidden, a, b, x) << endl;

    return 0;
}