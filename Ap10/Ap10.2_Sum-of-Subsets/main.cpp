#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <stack>
#include <algorithm>
#include <queue>
#include <climits>
#include <string>
using namespace std;

int promising(vector<int> arr, vector<int> save, int z, int W) {
	int sum = 0;
	for (int i = 0; i < save.size(); i++)
		sum += save[i];
	if (sum <= W) return sum;
	return -1;
}

void solve(vector<int> arr, vector<int> save, int n, int W, int z, vector<vector<int>> &result) {
	
	int a = promising(arr, save, z, W);

	if (a <= W && a >= 0) {
		if (z == n) {
			if (a == W) result.push_back(save);
		}				
		else {
			vector<int> temp = save;
			temp.push_back(arr[z + 1]);
			solve(arr, temp, n, W, z + 1, result);
			solve(arr, save, n, W, z + 1, result);
		}
	}	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, W, a, sum = 0;
	cin >> n >> W;
	vector<int> arr, save;
	vector<vector<int>> result;
	arr.push_back(0);
	for (int i = 0; i < n; i++) {
		cin >> a;
		arr.push_back(a);
	}

	solve(arr, save, n, W, 0, result);

	cout << result.size() << endl;
	if (!result.empty()) {
		for (auto iter = result.begin(); iter != result.end(); iter++) {
			for (auto it = iter->begin(); it != iter->end(); it++) {
				if(it == iter->begin()) cout << *it;
				else cout << " " << *it;
			}
			cout << endl;
		}
	}

	return 0;
}