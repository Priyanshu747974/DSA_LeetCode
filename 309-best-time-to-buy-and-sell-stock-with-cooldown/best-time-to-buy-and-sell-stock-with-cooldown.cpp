class Solution {
public:
    int function(int ind, int canbuy, vector<int>& prices, vector<vector<int>>& dp){
        if(ind >= prices.size()){
            return 0;
        }
        if(dp[ind][canbuy]!=-1){
            return dp[ind][canbuy];
        }
        if(canbuy==1){
            return dp[ind][canbuy] = max(-prices[ind]+function(ind+1,0,prices,dp),function(ind+1,1,prices,dp));
        }
        else{
            return dp[ind][canbuy] = max(prices[ind]+function(ind+2,1,prices,dp),function(ind+1,0,prices,dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return function(0,1,prices,dp);
    }
};