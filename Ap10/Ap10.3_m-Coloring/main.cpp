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

int promising(vector<vector<int>> G, vector<int> color, int a) {
	for (auto iter = G[a].begin(); iter != G[a].end(); iter++) {
		//cout << color[*iter] << " " << color[a] << endl;
		if (color[*iter] == color[a]) return -1;
	}
	set<int> set;
	for (int i = 1; i < color.size(); i++) {
		if (color[i] != -1) set.insert(color[i]);
	}
	return set.size();
}

void solve(vector<vector<int>> G, vector<int> color, int &m, int a) {
	int b = promising(G, color, a);
	//cout << a << " " << b << endl;
	if (b > 0) {
		if (G.size() - 1 == a) {
			if (m > b) {
				m = b;
			}
		}
		else {
			for (int i = 1; i <= a + 1; i++) {
				color[a + 1] = i;
				solve(G, color, m, a + 1);
			}
		}
	}
	if (a == 0) {
		color[a + 1] = 1;
		solve(G, color, m, a + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, a, b,m=INT_MAX,c=0;

	cin >> N >> M;
	vector<vector<int>> G(N + 1);
	vector<int> color(N + 1, -1);

	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	solve(G, color, m, 0);
	c = 1;
	for (int i = 1; i <= m; i++) {
		c *= i;
	}

	cout << m << endl << c;
	
	return 0;
}