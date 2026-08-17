class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1)
            return {0};

        vector<int> degree(n, 0);
        queue<int> q;
        vector<vector<int>> adj(n);
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];

            degree[u]++;
            degree[v]++;
        }

        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) {
                q.push(i);
            }
        }
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int remainingNodes = n;
        while (remainingNodes > 2) {
            int m = q.size();
            for (int i = 0; i < m; i++) {
                int node = q.front();
                q.pop();
                remainingNodes--;
                for (auto neighbor : adj[node]) {
                    degree[neighbor]--;
                    if (degree[neighbor] == 1) {
                        q.push(neighbor);
                    }
                }
            }
        }
        vector<int> ans(q.size());
        if (q.size() == 1) {
            ans[0] = q.front();
        } else {
            ans[0] = q.front();
            ans[1] = q.back();
        }
        return ans;
    }
};