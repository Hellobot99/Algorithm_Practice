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

typedef long long t;

t how_many = 0, c = 0;

void hanoi(int n, int k, char src, char via, char dst) {
    how_many++;
    if (n == 1) {
        c++;
        if (c == k) cout << src << " -> " << dst << endl;
    }
    else {
        hanoi(n - 1, k, src, dst, via);
        hanoi(1, k, src, via, dst);
        hanoi(n - 1, k, via, src, dst);
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    t n, m = 0, k;
    cin >> n >> k;
    hanoi(n, k, 'A', 'B', 'C');
    cout << how_many;
    return 0;
}