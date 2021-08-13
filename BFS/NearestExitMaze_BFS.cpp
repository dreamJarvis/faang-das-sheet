#include <bits/stdc++.h>
using namespace std;

int nearestExit(vector<vector<char>> &maze, vector<int> &e){
	queue<pair<int, int>> q;
	q.push({e[0], e[1]});

	int moves = 1;
	int rows = maze.size();
	int cols = maze[0].size();

	vector<vector<int>> offsets = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

	maze[e[0]][e[1]] = '+';
	while(!q.empty()){
		int qs = q.size();

		for(int i = 0; i < qs; i++){
			pair<int, int> point = q.front();
			q.pop();

			for (int k = 0; k < 4; k++){
				int x = point.first + offsets[k][0];
				int y = point.second + offsets[k][1];


				// if we cross the maze
				if(x < 0 || y < 0 ||  x >= rows || y >= cols || maze[x][y] == '+')	continue;

				// if we have already reached the border of the maze, return the moves
				if(x == 0 || y == 0 || x == rows-1 || y == cols-1)	return moves;

				maze[x][y] = '+';
				q.push({x, y});
			}
		}

		moves++;
	}

	return -1;
}

int main(){
	vector<vector<char>> maze{
        {'+','+','.','+'},
        {'.','.','.','+'},
        {'+','+','+','.'}
    };

    vector<int> entrance({1, 2});

    cout << nearestExit(maze, entrance) << endl;
}