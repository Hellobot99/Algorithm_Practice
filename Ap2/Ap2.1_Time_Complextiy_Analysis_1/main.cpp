#include <iostream>
using namespace std;

typedef long long long_t;

long_t fun(long_t n) {
    long_t i, j, cnt = 0;
    for (i = 1; i <= 4 * n; i += 2)
        cnt += n;
    return cnt;
}

int main() {
    long_t n;
    cin >> n;
    cout << fun(n);

    return 0;
}