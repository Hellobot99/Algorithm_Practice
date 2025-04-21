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

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, s, e;
    cin >> N;

    vector<pair<int, int>> result;

    priority_queue<pair<int, int>,vector<pair<int,int>>, greater<>> pq;

    for (int i = 0; i < N; i++) {
        cin >> s >> e;
        pq.push(make_pair(e, s));
    }

    while (!pq.empty()) {
        pair<int, int> cur = pq.top();
        pq.pop();
        if (result.empty()) 
            result.push_back(cur);        
        else 
            if (result.back().first <= cur.second) 
                result.push_back(cur);        
    }

    cout << result.size() << endl;
    for (auto i : result) 
        cout << i.second << " " << i.first << endl;    

    return 0;
}