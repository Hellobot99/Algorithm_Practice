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

int c = 0;
map<pair<int, int>, int> m;
int bin(int n, int k) {
    c++;
    pair<int, int> p = make_pair(n, k);
    if (k == 0 || k == n) return 1;
    else if (m.find(p) != m.end()) return m[p];
    else {
        m[p] = (bin(n - 1, k - 1) + bin(n - 1, k)) % 10007;
        return m[p];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;
    if (K > (N / 2)) K = N - K;
    cout << bin(N, K) << endl << c;

    return 0;
}
