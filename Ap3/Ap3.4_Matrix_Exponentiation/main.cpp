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

int K, N;
vector < vector <int>> arr;
vector < vector <int>> I;

vector<vector<int>> multiply(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    vector<vector<int>> result(N, vector<int>(N, 0));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                result[i][j] += (A[i][k] * B[k][j]) % 1000;
                result[i][j] %= 1000;
            }
        }
    }

    return result;
}
vector<vector<int>> solve(vector<vector<int>> b, int k) {
    if (k == 0) return I;
    else if (k == 1) return b;
    else {
        vector<vector<int>> h = solve(b, k / 2);
        vector<vector<int>> result = multiply(h, h);
        if (k % 2 == 1) {
            result = multiply(result, b);
        }
        return result;
    }
}

int main() {
    int a;
    cin >> N >> K;
    arr.resize(N, vector<int>(N, 0));
    I.resize(N, vector<int>(N, 0));
    vector<vector<int>> result;

    for (int i = 0; i < N; i++) {
        I[i][i] = 1;
    }

    for (int i = 0; i < N; i++) {
        for (int k = 0; k < N; k++) {
            cin >> arr[i][k];
        }
    }

    result = solve(arr, K);

    for (int i = 0; i < N; i++) {
        for (int k = 0; k < N; k++) {
            if (k == N - 1) cout << result[i][k];
            else cout << result[i][k] << " ";
        }
        cout << endl;
    }

    return 0;
}