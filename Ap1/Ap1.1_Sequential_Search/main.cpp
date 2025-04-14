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

int sequential_search(vector<int> num, int a) {
    for (int i = 0; i < num.size(); i++) {
        if (num[i] == a) return i + 1;
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, a;

    cin >> N >> M;
    vector<int> num, have_to_search;

    for (int i = 0; i < N; i++) {
        cin >> a;
        num.push_back(a);
    }

    for (int i = 0; i < M; i++) {
        cin >> a;
        have_to_search.push_back(a);
    }

    for (auto iter = have_to_search.begin(); iter != have_to_search.end(); iter++) {
        a = sequential_search(num, *iter);
        if (a == -1) cout << *iter << " is not in S." << endl;
        else cout << *iter << " is in " << a << "." << endl;
    }

    return 0;
}