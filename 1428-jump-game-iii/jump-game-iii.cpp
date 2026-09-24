class Solution {
public:
    bool dfs(vector<int>& arr, int node, vector<int>& visited) {
        if (arr[node] == 0)
            return true;

        visited[node] = 1;

        int n = arr.size();

        int right = node + arr[node];
        if (right < n && !visited[right]) {
            if (dfs(arr, right, visited))
                return true;
        }

        int left = node - arr[node];
        if (left >= 0 && !visited[left]) {
            if (dfs(arr, left, visited))
                return true;
        }

        return false;
    }

    bool canReach(vector<int>& arr, int start) {
        vector<int> visited(arr.size(), 0);
        return dfs(arr, start, visited);
    }
};