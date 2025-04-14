#include <iostream>
#include<math.h>
using namespace std;

typedef long long long_t;

long_t fun(long_t n, long_t m, long_t p) {
    long_t i, j, k, cnt = 0;
    for (i = 1; i <= 2 * n; i += 4) {
        cnt += (2 + log2(m)) * (3 + log2(p));
    }
    return cnt;
}

int main() {

    long_t n, m, p;
    cin >> n >> m >> p;
    cout << fun(n, m, p);

    return 0;
}