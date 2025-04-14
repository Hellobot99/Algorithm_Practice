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

void solve(int n, vector<vector<int>>& a, vector<vector<int>>& b, vector<vector<int>>& c) {
    for (int i = n - 1; i >= 0; i--) {
        for (int k = 0; k < i + 1; k++) {
            if (b[i + 1][k] > b[i + 1][k + 1]) {
                b[i][k] = a[i][k] + b[i + 1][k];
                c[i][k] = -1;
            }
            else if (b[i + 1][k] == b[i + 1][k + 1]) {
                b[i][k] = a[i][k] + b[i + 1][k];
                c[i][k] = 1;
            }
            else {
                b[i][k] = a[i][k] + b[i + 1][k + 1];
                c[i][k] = 1;
            }
        }
    }
}

void print_path(int n, vector<vector<int>> ori, vector<vector<int>> arr) {
    int x = 0, y = 0;
    while (arr[x][y] != -2) {
        if (x != 0) cout << " ";
        cout << ori[x][y];
        if (arr[x][y] == 1) y++;
        x++;
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, n;
    cin >> T;

    for (int z = 0; z < T; z++) {
        cin >> n;
        vector<vector<int>> arr1(n + 1, vector<int>(n + 1, 0));
        vector<vector<int>> arr2(n + 1, vector<int>(n + 1, 0));
        vector<vector<int>> arr3(n + 1, vector<int>(n + 1, -2));
        for (int i = 0; i < n; i++)
            for (int k = 0; k < i + 1; k++)
                cin >> arr1[i][k];

        solve(n, arr1, arr2, arr3);

        cout << arr2[0][0] << endl;
        print_path(n, arr1, arr3);
    }

    return 0;
}