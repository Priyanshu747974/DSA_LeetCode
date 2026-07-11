class Solution {
public:
    int function(int m, int n,vector<vector<int>>& dp,vector<vector<int>>& obstacleGrid){
        if(m<0 || n<0) return 0;
        if(obstacleGrid[m][n]==1) return dp[m][n]= 0;
        if(m==0 && n==0) return dp[m][n]=1;

        if(dp[m][n]!= -1){
            return dp[m][n];
        }
        return dp[m][n]=function(m-1,n,dp,obstacleGrid)+function(m,n-1,dp,obstacleGrid);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return function(m-1,n-1,dp,obstacleGrid);
    }
};