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

#define INF 999
typedef vector<vector<int>> matrix_t;
void floyd(int n, matrix_t& W, matrix_t& D, matrix_t& P)
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            P[i][j] = 0;
            D[i][j] = W[i][j];
        }

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) {
                if (D[i][j] > D[i][k] + D[k][j]) {
                    D[i][j] = D[i][k] + D[k][j];
                    P[i][j] = k;
                }
            }
}

void print_matrix(matrix_t a, int n) {
    for (int i = 1; i <= n; i++) {
        for (int k = 1; k <= n; k++) {
            if (k != n) cout << a[i][k] << " ";
            else cout << a[i][k] << endl;
        }
    }
}

void path(matrix_t& P, int u, int v, vector<int>& p)
{
    int k = P[u][v];
    if (k != 0) {
        path(P, u, k, p);
        p.push_back(k);
        path(P, k, v, p);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, x, y, z, K;
    cin >> N >> M;
    matrix_t A(N + 1, vector<int>(N + 1, INF));
    matrix_t B(N + 1, vector<int>(N + 1, INF));
    matrix_t P(N + 1, vector<int>(N + 1, 0));
    vector<int> p;
    for (int i = 0; i < M; i++) {
        cin >> x >> y >> z;
        A[x][y] = z;
    }

    for (int i = 1; i <= N; i++) {
        A[i][i] = 0;
    }

    floyd(N, A, B, P);

    print_matrix(B, N);

    print_matrix(P, N);

    cin >> K;
    for (int i = 0; i < K; i++) {
        cin >> x >> y;
        if (B[x][y] != INF) {
            p.clear();
            path(P, x, y, p);
            cout << x << " ";
            for (int i = 0; i < p.size(); i++) cout << p[i] << " ";
            cout << y << endl;
        }
        else cout << "NONE" << endl;
    }


    return 0;
}