class Solution {
public:
    int function(int ind, int tran, vector<int>& prices, int k, vector<vector<int>>& dp) {
        if (ind >= prices.size() || tran == 2 * k) {
            return 0;
        }
        if (dp[ind][tran] != -1) {
            return dp[ind][tran];
        }
        if (tran % 2 == 0) {
            return dp[ind][tran] =
                       max(-prices[ind] +
                               function(ind + 1, tran + 1, prices, k, dp),
                           function(ind + 1, tran, prices, k, dp));
        } else {
            return dp[ind][tran] = max(
                       prices[ind] + function(ind + 1, tran + 1, prices, k, dp),
                       function(ind + 1, tran, prices, k, dp));
        }
    }
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2 * k, -1));
        return function(0, 0, prices, k, dp);
    }
};