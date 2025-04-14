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

int sum(int n, vector<int>& S)
{
    int result = 0;
    for (int i = 0; i < n; i++)
        result += S[i];
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, a;

    cin >> N;
    vector<int> num;

    for (int i = 0; i < N; i++) {
        cin >> a;
        num.push_back(a);
    }

    cout << sum(N, num);

    return 0;
}