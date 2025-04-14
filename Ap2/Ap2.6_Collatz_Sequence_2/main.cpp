#include <iostream>
#include <cmath> 
using namespace std;

typedef long long t;

int c = 0;

void solve(t n) {
    if (n == 1) {
        return;
    }
    if (n % 2) {
        solve(3 * n + 1);
        c++;
    }
    else {
        solve(n / 2);
        c++;
    }
}

void print(t n) {
    if (n == 1) {
        cout << "1";
        return;
    }
    if (n % 2) {
        cout << n << " ";
        print(3 * n + 1);
    }
    else {
        cout << n << " ";
        print(n / 2);
    }
}

t fun(t n, t m) {
    t a;
    int max = 0, length = 0;
    for (t i = n; i <= m; i++) {
        c = 0;
        solve(i);
        if (c > length) {
            max = i;
            length = c;
        }
    }
    cout << max << " " << length << endl;
    print(max);
    return 0;
}

int main() {

    t n, m;
    cin >> n >> m;
    fun(n, m);
    return 0;
}