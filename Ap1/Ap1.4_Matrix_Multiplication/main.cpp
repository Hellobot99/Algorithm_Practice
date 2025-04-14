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

typedef vector<vector<int>> matrix_t;

void matrixmult(int n, matrix_t A, matrix_t B, matrix_t& C)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;

    cin >> N;

    matrix_t A(N + 1, vector<int>(N + 1));
    matrix_t B(N + 1, vector<int>(N + 1));
    matrix_t C(N + 1, vector<int>(N + 1));

    for (int i = 0; i < N; i++) {
        for (int k = 0; k < N; k++) {
            cin >> A[i][k];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int k = 0; k < N; k++) {
            cin >> B[i][k];
        }
    }

    matrixmult(N, A, B, C);

    for (int i = 0; i < N; i++) {
        for (int k = 0; k < N; k++) {
            if (k == N - 1)cout << C[i][k] << endl;
            else cout << C[i][k] << " ";
        }
    }

    return 0;
}