class Solution {
public:
    int function(int i,int j,vector<int>& piles, vector<vector<int>>& dp){
        int n = j-i+1;
        if(n==1){
            return piles[i];
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int takeleft = piles[i] - function(i+1,j,piles,dp);
        int takeright = piles[j] - function(i,j-1,piles,dp);

      return dp[i][j]=max(takeleft,takeright);
    }
    bool stoneGame(vector<int>& piles) {
        vector<vector<int>> dp(piles.size(),vector<int>(piles.size(),-1));
        int diff = function(0,piles.size()-1,piles,dp);
        if(diff>=0){
            return true;
        }
        return false;
    }
};