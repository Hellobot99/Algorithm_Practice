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

void dijkstra(int n, matrix_t& W, set_of_edges& F, vector<int>& tt);

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, u, v, k, w, t, b;
    edge_t a;
    vector<int> tc, tt;

    set_of_edges F;

    cin >> n >> k;

    matrix_t W(n + 1, vector<int>(n + 1, INF));

    for (int i = 0; i < k; i++) {
        cin >> u >> v >> w;
        W[u][v] = w;
    }


    dijkstra(n, W, F, tt);

    for (edge_t e : F)
        cout << e.u << " " << e.v << " " << e.w << endl;

    cin >> t;

    int s = 1;
    tt[1] = 1;

    stack<int> temp;

    for (int i = 0; i < t; i++) {
        cin >> b;
        if(b != tt[b]) temp.push(b);
        while (1) {
            temp.push(tt[b]);
            if (tt[b] == s) {
                break;
            }
            else {
                b = tt[b];
            }
        }
        while (!temp.empty()) {
            cout << temp.top();
            if (temp.size() == 1) cout << endl;            
            else cout << " ";
            temp.pop();
        }
    }    

    return 0;
}

void dijkstra(int n, matrix_t& W, set_of_edges& F, vector<int>& tt)
{
    int vnear, min;
    vector<int> touch(n + 1), length(n + 1);

    F.clear();
    for (int i = 2; i <= n; i++) {
        touch[i] = 1;
        length[i] = W[1][i];
    }

    for (int i = 2; i <= n; i++) {
        if (i == n) cout << touch[i] << endl;
        else cout << touch[i] << " ";
    }

    for (int z = 0; z < n - 1; z++) {
        min = INF;
        for (int i = 2; i <= n; i++)
            if (0 <= length[i] && length[i] < min) {
                min = length[i];
                vnear = i;
            }
        edge_t a;
        a.v = vnear;
        a.u = touch[vnear];
        a.w = W[a.u][a.v];
        F.push_back(a);

        for (int i = 2; i <= n; i++)
            if (length[i] > length[vnear] + W[vnear][i]) {
                length[i] = length[vnear] + W[vnear][i];
                touch[i] = vnear;
            }
        length[vnear] = -1;

        for (int i = 2; i <= n; i++) {
            if (i == n) cout << touch[i] << endl;
            else cout << touch[i] << " ";
        }
    }
    tt = touch;
}
