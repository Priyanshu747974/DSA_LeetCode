class Solution {
public:
    int dfs(int node, vector<vector<int>>& adj, vector<int> & vis, int& cnt){
        vis[node]=1;
        for(auto it : adj[node]){
            if(vis[it]!=1){
                cnt ++;
                dfs(it,adj,vis,cnt);
            }
        }
        return cnt;
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int> vis(rooms.size(),0);
        int cnt =1;
        dfs(0,rooms,vis,cnt);
        if(cnt == rooms.size()){
            return true;
        }
        return false;
    }
};