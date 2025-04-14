#include <iostream>
#include<math.h> 
using namespace std;

typedef long long long_t;

long_t fun(long_t n) {
    return 4 * n * n;
}

int main() {

    long_t n;
    cin >> n;
    cout << fun(n);

    return 0;
}