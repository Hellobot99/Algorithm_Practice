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

int threshold = 1, cf = 0;
#define matrix_t vector<vector<int>>

void resize(int n, matrix_t& mat);
void madd(int n, matrix_t A, matrix_t B, matrix_t& C);
void msub(int n, matrix_t A, matrix_t B, matrix_t& C);
void mmult(int n, matrix_t A, matrix_t B, matrix_t& C);
void partition(int m, matrix_t M, matrix_t& M11, matrix_t& M12, matrix_t& M21, matrix_t& M22);
void strassen(int n, matrix_t A, matrix_t B, matrix_t& C);
void combine(int n, matrix_t& C, matrix_t C11, matrix_t C12, matrix_t C21, matrix_t C22);

void strassen(int n, matrix_t A, matrix_t B, matrix_t& C) {
    cf++;
    if (n <= threshold) {
        mmult(n, A, B, C);
    }
    else {
        int m = n / 2;
        matrix_t A11, A12, A21, A22;
        matrix_t B11, B12, B21, B22;
        matrix_t C11, C12, C21, C22;
        matrix_t M1, M2, M3, M4, M5, M6, M7;
        matrix_t L, R;

        resize(m, A11); resize(m, A12); resize(m, A21); resize(m, A22);
        resize(m, B11); resize(m, B12); resize(m, B21); resize(m, B22);
        resize(m, C11); resize(m, C12); resize(m, C21); resize(m, C22);
        resize(m, M1); resize(m, M2); resize(m, M3); resize(m, M4); resize(m, M5);
        resize(m, M6); resize(m, M7); resize(m, L); resize(m, R);

        partition(m, A, A11, A12, A21, A22);
        partition(m, B, B11, B12, B21, B22);

        madd(m, A11, A22, L);
        madd(m, B11, B22, R);
        strassen(m, L, R, M1);

        madd(m, A21, A22, L);
        strassen(m, L, B11, M2);

        msub(m, B12, B22, R);
        strassen(m, A11, R, M3);

        msub(m, B21, B11, R);
        strassen(m, A22, R, M4);

        madd(m, A11, A12, L);
        strassen(m, L, B22, M5);

        msub(m, A21, A11, L);
        madd(m, B11, B12, R);
        strassen(m, L, R, M6);

        msub(m, A12, A22, L);
        madd(m, B21, B22, R);
        strassen(m, L, R, M7);

        madd(m, M1, M4, L);
        msub(m, L, M5, R);
        madd(m, R, M7, C11);

        madd(m, M3, M5, C12);

        madd(m, M2, M4, C21);

        madd(m, M1, M3, L);
        msub(m, L, M2, R);
        madd(m, R, M6, C22);

        combine(m, C, C11, C12, C21, C22);
    }
}

void partition(int n, matrix_t M, matrix_t& M11, matrix_t& M12, matrix_t& M21, matrix_t& M22) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            M11[i][j] = M[i][j];
            M12[i][j] = M[i][j + n];
            M21[i][j] = M[i + n][j];
            M22[i][j] = M[i + n][j + n];
        }
}

void combine(int n, matrix_t& C, matrix_t C11, matrix_t C12, matrix_t C21, matrix_t C22) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            C[i][j] = C11[i][j];
            C[i][j + n] = C12[i][j];
            C[i + n][j] = C21[i][j];
            C[i + n][j + n] = C22[i][j];
        }
}

void resize(int n, matrix_t& mat) {
    mat.resize(n);
    for (auto& row : mat) {
        row.resize(n);
    }
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n; k++)
            mat[i][k] = 0;
    }
}

void madd(int n, matrix_t A, matrix_t B, matrix_t& C) {
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n; k++) {
            C[i][k] = A[i][k] + B[i][k];
        }
    }
}

void msub(int n, matrix_t A, matrix_t B, matrix_t& C) {
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n; k++) {
            C[i][k] = A[i][k] - B[i][k];
        }
    }
}

void mmult(int n, matrix_t A, matrix_t B, matrix_t& C) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                C[i][j] += (A[i][k] * B[k][j]);
            }
        }
    }
}

void print_matrix(int n, matrix_t A) {
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n; k++) {
            if (k == n - 1) cout << A[i][k];
            else cout << A[i][k] << " ";
        }
        cout << endl;
    }
}

int main() {

    int N, v = 1;
    cin >> N >> threshold;
    while (v < N) {
        v *= 2;
    }

    vector<vector<int >> a(v, vector<int>(v, 0));
    vector<vector<int>> b(v, vector<int>(v, 0));
    vector<vector<int>> c(v, vector<int>(v, 0));

    for (int i = 0; i < N; i++) {
        for (int k = 0; k < N; k++) {
            cin >> a[i][k];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int k = 0; k < N; k++) {
            cin >> b[i][k];
        }
    }

    strassen(v, a, b, c);
    cout << cf << endl;
    print_matrix(N, c);

    return 0;
}