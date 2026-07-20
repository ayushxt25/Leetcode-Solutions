class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        vector<vector<pair<int, int>>> graph(n);

        for (auto& e : edges) {
            graph[e[0]].push_back({e[1], e[2]});
            graph[e[1]].push_back({e[0], e[2]});
        }

        vector<int> dist(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        dist[0] = 0;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();

            if (d > dist[node]) continue;

            for (auto& [next, cnt] : graph[node]) {
                int nd = d + cnt + 1;

                if (nd < dist[next] && nd <= maxMoves) {
                    dist[next] = nd;
                    pq.push({nd, next});
                }
            }
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (dist[i] <= maxMoves) ans++;
        }

        for (auto& e : edges) {
            int a = dist[e[0]] == INT_MAX ? 0 : max(0, maxMoves - dist[e[0]]);
            int b = dist[e[1]] == INT_MAX ? 0 : max(0, maxMoves - dist[e[1]]);
            ans += min(e[2], a + b);
        }

        return ans;
    }
};