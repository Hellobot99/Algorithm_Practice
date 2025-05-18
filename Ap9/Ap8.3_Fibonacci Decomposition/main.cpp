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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	unsigned long long fib[100], input;
	fib[0] = 0;
	fib[1] = 1;
	fib[2] = 1;

	int i;

	cin >> input;

	for (i = 3; i < 500; i++) {
		fib[i] = fib[i - 1] + fib[i - 2];
		if (fib[i] > input) break;
	}

	stack<unsigned long long> st;

	while (input > 0) {
		if (input >= fib[i]) {
			input -= fib[i];
			st.push(fib[i--]);
		}
		else i--;
	}

	while (!st.empty()) {
		cout << st.top() << endl;
		st.pop();
	}

	return 0;
}