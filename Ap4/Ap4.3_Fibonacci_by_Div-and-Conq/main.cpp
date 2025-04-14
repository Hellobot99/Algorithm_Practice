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

vector<vector<int>> divide(vector<vector<int>> a, long long n);
int Fib(long long n);
vector<vector<int>> multiply(vector<vector<int>> A, vector<vector<int>> B);

vector<vector<int>> multiply(vector<vector<int>> A, vector<vector<int>> B) {
    vector<vector<int>> result(2, vector<int>(2, 0));

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                result[i][j] += (A[i][k] * B[k][j]) % 10007;
                result[i][j] %= 10007;
            }
        }
    }

    return result;
}

int Fib(long long n) {
    vector<vector<int>> a(2, vector<int>(2, 0));
    a[0][0] = a[0][1] = a[1][0] = 1;
    vector<vector<int>> b = divide(a, n);
    return b[0][1];
}

vector<vector<int>> divide(vector<vector<int>> a, long long n) {
    if (n == 1) {
        return a;
    }
    else {
        long long m = n / 2;
        if (n % 2) {
            vector<vector<int>> temp = divide(a, m);
            temp = multiply(temp, temp);
            return multiply(temp, a);
        }
        else {
            vector<vector<int>> temp = divide(a, m);
            return multiply(temp, temp);
        }
    }
}

int main() {
    long long n;

    cin >> n;
    cout << Fib(n);

    return 0;
}