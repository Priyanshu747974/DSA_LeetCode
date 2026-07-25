class Solution {
public:
    int function(int ind, int tran, vector<int>& prices, int k,
                 vector<vector<int>>& dp) {
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
        vector<vector<int>> dp(prices.size()+1, vector<int>(2 * k+1, -1));
        int n = prices.size();
        for (int i = 0; i <= 2 * k; i++) {
            dp[n][i] = 0;
        }
        for (int i = 0; i < n; i++) {
            dp[i][2 * k] = 0;
        }
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int tran = 0; tran < 2 * k; tran++) {
                if (tran % 2 == 0) {
                    dp[ind][tran] = max(-prices[ind] + dp[ind + 1][tran + 1],
                                        dp[ind + 1][tran]);
                } else {
                    dp[ind][tran] = max(prices[ind] + dp[ind + 1][tran + 1],
                                        dp[ind + 1][tran]);
                }
            }
        }
        return dp[0][0];
    }
};