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

bool promising(int i, int col[]) {
	int k = 1;
	bool flag = true;

	while (k < i && flag) {
		if ((col[i] == col[k]) || (abs(col[i] - col[k]) == i - k))
			flag = false;
		k++;
	}
	return flag;
}

void solve(int N, int a, int& c, string& s, int col[]) {
	if (promising(a, col)) {
		if (a == N) {
			c++;
			string sum;
			for (int i = 1; i <= N; i++) 
				sum = sum + to_string(col[i]);
			
			if (sum > s) s = sum;
		}
		else {
			for (int i = 1; i <= N; i++) {
				col[a + 1] = i;
				solve(N, a + 1, c, s, col);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, a, b = 0;
	string s;
	int col[100];
	for (int i = 0; i < 100; i++) {
		col[i] = 0;
	}

	cin >> N;

	solve(N, 0, b, s, col);
	
	cout << b << endl << s;

	return 0;
}