class Solution {
public:
    int function(int ind, int canbuy, vector<int>& prices,
                 vector<vector<int>>& dp) {
        if (ind >= prices.size()) {
            return 0;
        }
        if (dp[ind][canbuy] != -1) {
            return dp[ind][canbuy];
        }
        if (canbuy == 1) {
            return dp[ind][canbuy] =
                       max(-prices[ind] + function(ind + 1, 0, prices, dp),
                           function(ind + 1, 1, prices, dp));
        } else {
            return dp[ind][canbuy] =
                       max(prices[ind] + function(ind + 2, 1, prices, dp),
                           function(ind + 1, 0, prices, dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+2, vector<int>(2, -1));
        for (int i = 0; i < 2; i++) {
            dp[n+1][i] = 0;
            dp[n][i]=0;
        }
        for (int ind = n-1; ind >= 0; ind--) {
            for (int canbuy = 0; canbuy < 2; canbuy++) {
                if (canbuy == 1) {
                    dp[ind][canbuy] = max(
                               -prices[ind] + dp[ind + 1][0],
                               dp[ind + 1][1]);
                } else {
                    dp[ind][canbuy] = max(
                               prices[ind] + dp[ind + 2][1],
                               dp[ind + 1][0]);
                }
            }
        }
        return dp[0][1];
    }
};