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

int x, c = 0;
vector<int> S, f;
void merge2(int low, int mid, int high);
void mergesort2(int low, int high)
{
    if (low < high) {
        int mid = (low + high) / 2;
        mergesort2(low, mid);
        mergesort2(mid + 1, high);
        merge2(low, mid, high);
    }
}

void merge2(int low, int mid, int high) {
    c++;
    int i = low, j = mid + 1, k = 0;
    vector<int> U(high - low + 1);
    while (i <= mid && j <= high)
        U[k++] = (S[i] < S[j]) ? S[i++] : S[j++];
    if (i > mid)
        // move S[j] through S[high] to U[k] through U[high]
        while (j <= high)
            U[k++] = S[j++];
    else // j > high
    // move S[i] through S[mid] to U[k] through U[high]
        while (i <= mid)
            U[k++] = S[i++];
    // move U[0] through U[high-low+1] to S[low] through S[high]
    for (int t = low; t <= high; t++)
        S[t] = U[t - low];
}

int main() {

    int N, a;
    cin >> N;
    S.push_back(-1);
    for (int i = 0; i < N; i++) {
        cin >> a;
        S.push_back(a);
    }

    mergesort2(1, N);
    for (int i = 1; i < N + 1; i++) {
        if (i == N) cout << S[i];
        else cout << S[i] << " ";
    }

    cout << endl << c;

    return 0;
}