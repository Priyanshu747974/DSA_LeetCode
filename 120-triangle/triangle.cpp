class Solution {
public:
    int function(int m,int n, vector<vector<int>>& triangle ,vector<vector<int>>& dp){
        if(m==0 && n==0){
            return dp[m][n]=triangle[m][n];
        }
        if(m<0 || n<0 || n >= triangle[m].size()){
            return 1e9;
        }
        if(dp[m][n]!=-1){
            return dp[m][n];
        }
        int down = function(m-1,n,triangle,dp);
        int dright= function(m-1,n-1,triangle,dp);

        return dp[m][n] = triangle[m][n]+min(down,dright);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n = triangle[m-1].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        dp[0][0]=triangle[0][0];
        for(int i=1 ;i<m;i++){
            for(int j=0;j<=i;j++){
                int down = 1e9;
                if (j < i){
                    down = dp[i-1][j];
                }
                int dright = 1e9;
                if (j > 0){
                    dright = dp[i-1][j-1];
                }
                dp[i][j]= triangle[i][j] + min(down,dright);
            }
        }
        int ans=1e9;
        for(int i=0;i<triangle[m-1].size();i++){
            ans=min(ans,dp[m-1][i]);
        }
        return ans;
    }
};