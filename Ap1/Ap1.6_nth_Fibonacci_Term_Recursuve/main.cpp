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

LongInt fib(LongInt n, int& count)
{
    count++;
    if (n <= 1)
        return n;
    else
        return fib(n - 1, count) + fib(n - 2, count) % 1000000;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, a = 0, b;

    cin >> N;

    cout << fib(N, a) << endl << a;

    return 0;
}