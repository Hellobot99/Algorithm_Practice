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

string a;
int s_idx = 0;

void solve(int N, vector<vector<int>>& arr, int x, int y) {
    if (a.size() - 1 < s_idx) return;
    int m = N / 2;
    switch (a[s_idx]) {
    case 'x':
        s_idx++;
        solve(m, arr, x, y);
        solve(m, arr, x, y + m);
        solve(m, arr, x + m, y);
        solve(m, arr, x + m, y + m);
        break;
    case 'w':
        s_idx++;
        for (int i = x; i < x + N; i++) {
            for (int k = y; k < y + N; k++) {
                arr[i][k] = 0;
            }
        }
        break;
    case 'b':
        s_idx++;
        for (int i = x; i < x + N; i++) {
            for (int k = y; k < y + N; k++) {
                arr[i][k] = 1;
            }
        }
        break;
    }
}

int main() {

    int N;
    cin >> N;

    cin >> a;
    vector<vector<int>> arr(N, vector<int>(N, 0));

    solve(N, arr, 0, 0);

    cout << N << endl;
    for (int i = 0; i < N; i++) {
        for (int k = 0; k < N; k++) {
            if (k == N - 1) cout << arr[i][k] << endl;
            else cout << arr[i][k] << " ";
        }
    }

    return 0;
}