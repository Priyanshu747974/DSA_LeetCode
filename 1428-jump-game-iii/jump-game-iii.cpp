class Solution {
public:
    bool dfs(vector<vector<int>>& adj, int node,vector<int>& visited,vector<int>& arr){
        if(arr[node]==0){
            return true;
        }
        
        visited[node]=1;
        for(auto it : adj[node]){
            if(visited[it]==0){
                if (dfs(adj, it, visited, arr)) {
                    return true;
                }
            }
        }
        return false;
    }
    bool canReach(vector<int>& arr, int start) {
        vector<vector<int>> adj;
        for(int i =0;i<arr.size();i++){
            vector<int> list;
            if(i+arr[i]<arr.size()){
                list.push_back(i+arr[i]);
            }
            if(i-arr[i]>=0){
                list.push_back(i-arr[i]);
            }
            adj.push_back(list);
        }
        vector<int> visited(arr.size(),0);
        return dfs(adj,start,visited,arr);
    }
};