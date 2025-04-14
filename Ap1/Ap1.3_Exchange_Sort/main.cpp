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

void exchangesort(int n, vector<int>& S, int& count)
{
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (S[i] > S[j]) {
                swap(S[i], S[j]);
                count++;
            }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, a, count = 0;

    cin >> N;
    vector<int> num;

    for (int i = 0; i < N; i++) {
        cin >> a;
        num.push_back(a);
    }

    exchangesort(N, num, count);

    for (auto iter = num.begin(); iter != num.end(); iter++) {
        if (iter == num.end() - 1) cout << *iter << endl << count;
        else cout << *iter << " ";
    }

    return 0;
}