#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    vector<vector<pair<int, int>>> adj(n+1);
    for (auto& t : times) {
        int u = t[0], v = t[1], w = t[2];
        adj[u].push_back({v, w});
    }
    
    vector<int> dist(n+1, INF);
    dist[k] = 0;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, k});
    
    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        
        if (d > dist[u]) continue;
        
        for (auto& p : adj[u]) {
            int v = p.first, w = p.second;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    
    int ans = *max_element(dist.begin()+1, dist.end());
    return (ans == INF) ? -1 : ans;
}

int main() {
    vector<vector<int>> times = {{2,1,1},{2,3,1},{3,4,1}};
    int n = 4, k = 2;
    int ans= networkDelayTime(times, n, k);
    cout << ans << endl;
    return 0;
}




