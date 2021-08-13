#include <bits/stdc++.h>
using namespace std;

int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
	int n = difficulty.size();
	int m = worker.size();

	vector<pair<int, int>> jobs;
	for(int i = 0; i < n; i++){
		jobs.push_back({difficulty[i], profit[i]});
	}

	sort(jobs.begin(), jobs.end());	
	sort(worker.begin(), worker.end());

	int totalProfit(0);

	int i(0), maxProfit(0);
	for(int ability:worker){
		while(i < n && ability >= jobs[i].first){
			maxProfit = max(maxProfit, jobs[i++].second);
		}

		totalProfit += maxProfit;
	}

	return totalProfit;
}

// Driver function	
int main(){
	// vector<int> difficulty({2,4,6,8,10});
	// vector<int> profit({10,20,30,40,50});
	// vector<int> worker({4,5,6,7});

	// vector<int> difficulty({85,47,57});
	// vector<int> profit({24,66,99});
	// vector<int> worker({40,25,25});

	// vector<int> difficulty({13,37,58});
	// vector<int> profit({4,90,96});
	// vector<int> worker({34,73,45});

	// vector<int> difficulty({68,35,52,47,86});
	// vector<int> profit({67,17,1,81,3});
	// vector<int> worker({92,10,85,84,82});

	vector<int> difficulty({5,50,92,21,24,70,17,63,30,53});
	vector<int> profit({68,100,3,99,56,43,26,93,55,25});
	vector<int> worker({96,3,55,30,11,58,68,36,26,1});

	cout << maxProfitAssignment(difficulty, profit, worker) << endl;

	return 0;
}

/*
[13,37,58]
[4,90,96]
[34,73,45]

[68,35,52,47,86]
[67,17,1,81,3]
[92,10,85,84,82]

[5,50,92,21,24,70,17,63,30,53]
[68,100,3,99,56,43,26,93,55,25]
[96,3,55,30,11,58,68,36,26,1]
*/