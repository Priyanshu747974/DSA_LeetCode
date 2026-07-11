class Solution {
public:
    int function(int m, int n, vector<vector<int>>& grid,vector<vector<int>>& ds){
        if(m == 0 && n==0){
            return ds[m][n] = grid[0][0];
        }
        if(m<0 || n<0){
            return 1e9;
        }
        if(ds[m][n]!=-1){
            return ds[m][n];
        }
        int down = function(m-1,n,grid,ds);
        int right = function(m,n-1,grid,ds);

        return ds[m][n] = grid[m][n] + min(down,right);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> ds(m,vector<int>(n,-1));
        return function(m-1,n-1,grid,ds);
    }
};