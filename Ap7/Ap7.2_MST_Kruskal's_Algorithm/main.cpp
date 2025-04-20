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

#define INF 0xffff
typedef vector<vector<int>> matrix_t;

typedef struct edge {
    int u, v, w;
} edge_t;

typedef vector<edge_t> set_of_edges;

struct edge_compare {
    bool operator()(edge_t e1, edge_t e2) {
        if (e1.w > e2.w) return true;
        else return false;
    }
};

typedef vector<edge_t> set_of_edges;
typedef priority_queue<edge_t, vector<edge_t>, edge_compare> PriorityQueue;

void kruskal(int n, set_of_edges& E, set_of_edges& F);
void dset_init(int n);
int dset_find(int i);
void dset_merge(int p, int q);

vector<int> dset;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, u, v, k, w;
    edge_t a;

    set_of_edges F, W;

    cin >> n >> k;

    for (int i = 0; i < k; i++) {
        cin >> a.u >> a.v >> a.w;
        W.push_back(a);
    }
    
    kruskal(n, W, F);

    for (edge_t e : F)
        cout << e.u << " " << e.v << " " << e.w << endl;

    return 0;
}

void kruskal(int n, set_of_edges& E, set_of_edges& F) {
    int p, q;
    edge_t e;
    PriorityQueue PQ;
    F.clear();
    dset_init(n);

    for (edge_t e : E)
        PQ.push(e);

    while (F.size() < n - 1) {
        e = PQ.top(); PQ.pop();
        p = dset_find(e.u);
        q = dset_find(e.v);
        if (p != q) {
            dset_merge(p, q);
            F.push_back(e);
        }
    }
}

void dset_init(int n) {
    dset.resize(n + 1);
    for (int i = 1; i <= n; i++)
        dset[i] = i;
}

int dset_find(int i) {
    while (dset[i] != i)
        i = dset[i];
    return i;
}

void dset_merge(int p, int q) {
    dset[p] = q;
}