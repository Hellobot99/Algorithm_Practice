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
typedef vector<pair<int, int>> set_of_edges;
typedef pair<int, int> edge_t;

void prim(int n, matrix_t& W, set_of_edges& F);

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, u, v, k, w;

    set_of_edges F;

    cin >> n >> k;
    matrix_t W(n + 1,vector<int>(n + 1, INF));


    for (int i = 0; i < k; i++) {
        cin >> u >> v >> w;
        W[u][v] = w;
        W[v][u] = w;
    }

    prim(n, W, F);
    

    for (edge_t e : F) {
        u = e.first; v = e.second;
        cout << u << " " << v << " " << W[u][v] << endl;
    }

    

    return 0;
}

void prim(int n, matrix_t& W, set_of_edges& F)
{
    int vnear, min;
    vector<int> nearest(n + 1), distance(n + 1);

    F.clear(); 

    for (int i = 2; i <= n; i++) {
        nearest[i] = 1;
        distance[i] = W[1][i];
    }

    for (int i = 2; i <= n; i++) {
        if (i == n) cout << nearest[i];
        else cout << nearest[i] << " ";
    }
    cout << endl;

    for(int z = 0; z < n - 1; z++) {

        min = INF;
        for (int i = 2; i <= n; i++)
            if (0 <= distance[i] && distance[i] < min) {
                min = distance[i];
                vnear = i;
            }

        F.push_back(make_pair(vnear, nearest[vnear]));
        distance[vnear] = -1;
        for (int i = 2; i <= n; i++)
            if (W[i][vnear] >= 0 && distance[i] > W[i][vnear]) {
                distance[i] = W[i][vnear];
                nearest[i] = vnear;
            } 

        for (int i = 2; i <= n; i++) {
            if (i == n) cout << nearest[i];
            else cout << nearest[i] << " ";
        }
        
        cout << endl;
    }
}