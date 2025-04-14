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

void partition(int low, int high, int& pivotpoint)
{
    int pivotitem = S[low];
    int j = low;
    for (int i = low + 1; i <= high; i++)
        if (S[i] < pivotitem) {
            j++;
            c++;
            swap(S[i], S[j]);
        }
    pivotpoint = j;
    swap(S[low], S[pivotpoint]);
    c++;
}

void quicksort(int low, int high)
{
    int pivotpoint;
    if (low < high) {
        partition(low, high, pivotpoint);
        quicksort(low, pivotpoint - 1);
        quicksort(pivotpoint + 1, high);
    }
}


int main() {

    int N, a;
    cin >> N;
    S.push_back(-1);
    for (int i = 0; i < N; i++) {
        cin >> a;
        S.push_back(a);
    }

    quicksort(1, N);

    for (int i = 1; i < N + 1; i++) {
        if (i == N)cout << S[i];
        else cout << S[i] << " ";
    }

    cout << endl << c;

    return 0;
}