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

typedef vector<int> sequence_of_integer;
bool is_feasible(sequence_of_integer& K, sequence_of_integer& deadline) {
	for (int i = 1; i < K.size(); i++)
		if (i > deadline[K[i]])
			return false;
	return true;
}

void schedule(int n, sequence_of_integer& deadline, sequence_of_integer& J) {
	sequence_of_integer K;
	J.clear();
	J.push_back(0); // for an empty job
	J.push_back(1);
	for (int i = 2; i <= n; i++) {
		// K = J with i added according to nondecreasing values of deadline[i];
		K.resize(J.size());
		copy(J.begin(), J.end(), K.begin());
		int j = 1;
		while (j < K.size() && deadline[K[j]] <= deadline[i])
			j++;
		K.insert(K.begin() + j, i);
		if (is_feasible(K, deadline)) {
			// J = K
			J.resize(K.size());
			copy(K.begin(), K.end(), J.begin());
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, a;
	vector<int> deadline, profit, J;
	deadline.push_back(0);
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a;
		deadline.push_back(a);
	}
	for (int i = 0; i < N; i++) {
		cin >> a;
		profit.push_back(a);
	}

	schedule(N, deadline, J);
	int sum = 0;
	queue<int> q;
	for (int b : J) {
		if (b == 0) continue;
		sum += profit[b - 1];
		q.push(profit[b - 1]);
	}

	cout << sum << endl;
	while (!q.empty()) {
		cout << q.front();
		q.pop();
		if (!q.empty()) cout << " ";
	}

	return 0;
}