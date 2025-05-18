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

void print_path(vector<int> arr) {
	for (int i = 0; i < arr.size(); i++)
		cout << arr[i] << " ";
	cout << endl;
}

bool promising(vector<int> path) {
	if (path.empty()) return true;
	int b = path.back();
	for (int i = 0; i < path.size() - 1; i++) {
		if (path[i] == b) return false;
	}
	return true;
}

void solve(vector<vector<int>> G, vector<int> path, int &c, int a, int n, int b) {
	//cout << a << " " << b << endl;
	if (promising(path)) {
		if (a == n) {
			if (find(G[b].begin(), G[b].end(), path[0]) != G[b].end()) {
				c++;
				//print_path(path);
			}
		}
		else {
			if (a == 0) {
				path.push_back(1);
				solve(G, path, c, a + 1, n, 1);
			}
			else {
				for (auto iter = G[b].begin(); iter != G[b].end(); iter++) {
					vector<int> temp = path;
					temp.push_back(*iter);
					solve(G, temp, c, a + 1, n, *iter);
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, a, b,m=0,c=0;

	cin >> N >> M;
	vector<vector<int>> G(N + 1);
	vector<int> path;

	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	solve(G, path, c, 0, N, m);

	cout << c;
	
	return 0;
}