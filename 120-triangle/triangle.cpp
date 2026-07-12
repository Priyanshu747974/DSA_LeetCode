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
        int ans = 1e9;
        for(int i = 0;i<n;i++){
            ans = min(ans,function(m-1,i,triangle,dp));
        }
        return ans;
    }
};