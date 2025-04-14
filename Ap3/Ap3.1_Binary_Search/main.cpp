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

int x, c = 0;
vector<int> S, f;

int binsearch2(int low, int high) {
    c++;
    int mid;
    if (low > high) return 0;
    else
    {
        mid = (low + high) / 2;
        if (x == S[mid]) return mid;
        else if (x < S[mid]) {
            return binsearch2(low, mid - 1);
        }
        else {
            return binsearch2(mid + 1, high);
        }
    }
}

int main() {

    int N, M, a;
    cin >> N >> M;
    S.push_back(-1);
    for (int i = 0; i < N; i++) {
        cin >> a;
        S.push_back(a);
    }

    sort(S.begin() + 1, S.end());

    for (int i = 0; i < M; i++) {
        cin >> x;
        int b = binsearch2(1, N);
        cout << c << " " << b << endl;
        c = 0;
    }
    return 0;
}