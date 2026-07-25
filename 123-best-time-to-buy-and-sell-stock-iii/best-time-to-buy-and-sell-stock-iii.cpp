class Solution {
public:
    int function(int ind, int canbuy, int cap, vector<int>& prices, vector<vector<vector<int>>>& dp) {
        if (ind >= prices.size()) {
            return 0;
        }
        if (cap == 2) {
            return 0;
        }
        if(dp[ind][canbuy][cap]!=-1){
            return dp[ind][canbuy][cap];
        }
        if (canbuy==1) {
            return  dp[ind][canbuy][cap] = max(-prices[ind] + function(ind + 1, 0, cap, prices,dp),
                       function(ind + 1, 1, cap, prices, dp));
        } else {
            return  dp[ind][canbuy][cap] = max(prices[ind] + function(ind + 1, 1, cap + 1, prices, dp),
                       function(ind + 1, 0, cap, prices, dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>>dp(prices.size(),vector<vector<int>>(2,vector<int>(3,-1)));
        return function(0,1,0,prices,dp);
    }
};