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

void solve(int N, vector<vector<int>> arr, int x, int y) {
    if (N == 1) {
        if (arr[x][y]) cout << "b";
        else cout << "w";
    }
    else {
        int sum = 0;
        for (int i = x; i < N + x; i++) {
            for (int k = y; k < N + y; k++) {
                sum += arr[i][k];
            }
        }
        if (sum == 0) {
            cout << "w";
        }
        else if (sum == (N * N)) {
            cout << "b";
        }
        else {
            int m = N / 2;
            cout << "x";
            solve(m, arr, x, y);
            solve(m, arr, x, y + m);
            solve(m, arr, x + m, y);
            solve(m, arr, x + m, y + m);
        }
    }
}

int main() {

    int N;
    cin >> N;
    vector<vector<int>> arr(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++) {
        for (int k = 0; k < N; k++) {
            cin >> arr[i][k];
        }
    }

    solve(N, arr, 0, 0);

    return 0;
}