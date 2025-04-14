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

void binsearch(int n, vector<int>& S, int x, int& location)
{
    int low, high, mid;
    low = 1; high = n;
    location = 0;
    while (low <= high && location == 0) {
        mid = (low + high) / 2;
        if (x == S[mid])
            location = mid;
        else if (x < S[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, a, b;

    cin >> N >> M;
    vector<int> arr;

    arr.push_back(INT_MIN);

    for (int i = 0; i < N; i++) {
        cin >> a;
        arr.push_back(a);
    }

    sort(arr.begin(), arr.end());

    for (int i = 0; i < M; i++) {
        cin >> a;
        binsearch(N, arr, a, b);
        if (b == 0) cout << a << " is not in S." << endl;
        else cout << a << " is in " << b << "." << endl;
    }

    return 0;
}