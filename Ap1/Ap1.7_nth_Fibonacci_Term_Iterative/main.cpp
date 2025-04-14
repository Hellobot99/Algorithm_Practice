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

typedef unsigned long long LongInt;

LongInt fib2(int n)
{
    vector<LongInt> F;
    if (n <= 1)
        return n;
    else {
        F.push_back(0);
        F.push_back(1);
        for (int i = 2; i <= n; i++)
            F.push_back((F[i - 1] + F[i - 2]) % 1000000);
        return F[n];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, a = 0, b;

    cin >> N;

    cout << fib2(N);

    return 0;
}