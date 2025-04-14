#include <iostream>
#include<cmath> 
using namespace std;

typedef long long long_t;

void fun(long_t n) {
    cout << n << endl;
    if (n == 1) return;
    if (n % 2) fun(3 * n + 1);
    else fun(n / 2);
}

int main() {

    long_t n;
    cin >> n;
    fun(n);

    return 0;
}