class Solution {
public:
    void dfs(vector<vector<int>>& adj,int source, int destination,vector<int>& vis,bool& ans){
        vis[source]=1;
        if(source==destination){
            ans = true;
            return;
        }
        for(auto it : adj[source]){
            if(vis[it]!=1){
                dfs(adj,it,destination,vis,ans);
            }
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for(auto it: edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        bool ans = false;
        vector<int> vis(n,0);
        dfs(adj,source,destination,vis,ans);
        return ans;
    }
};