class Solution {
public:
    int function(int i,int canbuy, vector<int>& prices, vector<vector<int>>& dp){
        if(i==prices.size()){
            return 0;
        }
        if(dp[i][canbuy]!=-1){
            return dp[i][canbuy];
        }
        if(canbuy==1){
            return dp[i][canbuy] = max(-prices[i] + function(i + 1, 0, prices, dp),function(i + 1, 1, prices, dp));
        }
        else{
            return dp[i][canbuy] = max(prices[i] + function(i + 1, 1, prices, dp),function(i + 1, 0, prices, dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp (prices.size(),vector<int>(2,-1));
        return function(0,1,prices,dp);
    }
};