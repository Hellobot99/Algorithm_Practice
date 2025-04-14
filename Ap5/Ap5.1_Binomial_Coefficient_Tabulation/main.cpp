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

int bin(int n, int k) {
    vector<int> A(n + 1);

    for (int i = 0; i <= n; i++) {
        for (int j = min(i, k); j >= 0; j--) {
            if (j == 0 || j == i)
                A[j] = 1;
            else
                A[j] = (A[j] + A[j - 1]) % 10007;
        }
    }

    return A[k];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;
    if (K > (N / 2)) K = N - K;
    cout << bin(N, K);

    return 0;
}