class Solution {
public:
    vector<vector<int>> adj;
    vector<int> vis;

    void dfs(int node) {
        vis[node] = 1;

        for (int nei : adj[node]) {
            if (!vis[nei]) {
                dfs(nei);
            }
        }
    }
    vector<int> remainingMethods(int n, int k,
                                 vector<vector<int>>& invocations) {
        adj.assign(n, {});
        vis.assign(n, 0);

        for (auto& edge : invocations) {
            adj[edge[0]].push_back(edge[1]);
        }
        dfs(k);
        for (auto& edge : invocations) {
            int u = edge[0];
            int v = edge[1];

            if (!vis[u] && vis[v]) {
                vector<int> ans;
                for (int i = 0; i < n; i++)
                    ans.push_back(i);
                return ans;
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (!vis[i])
                ans.push_back(i);
        }

        return ans;
    }
};