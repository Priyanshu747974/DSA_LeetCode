class Solution {
public:
    int function(int ind, int canbuy, int cap, vector<int>& prices,
                 vector<vector<vector<int>>>& dp) {
        if (ind >= prices.size()) {
            return 0;
        }
        if (cap == 2) {
            return 0;
        }
        if (dp[ind][canbuy][cap] != -1) {
            return dp[ind][canbuy][cap];
        }
        if (canbuy == 1) {
            return dp[ind][canbuy][cap] =
                       max(-prices[ind] + function(ind + 1, 0, cap, prices, dp),
                           function(ind + 1, 1, cap, prices, dp));
        } else {
            return dp[ind][canbuy][cap] = max(
                       prices[ind] + function(ind + 1, 1, cap + 1, prices, dp),
                       function(ind + 1, 0, cap, prices, dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(
            prices.size()+1, vector<vector<int>>(2, vector<int>(3, -1)));
        int n = prices.size();
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                dp[n][i][j] = 0;
            }
        }
        for (int ind = 0; ind <= n; ind++) {
            for (int canbuy = 0; canbuy <= 1; canbuy++) {
                dp[ind][canbuy][2] = 0;
            }
        }
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int canbuy = 1; canbuy >= 0; canbuy--) {
                for (int cap = 0; cap < 2; cap++) {
                    if (canbuy == 1) {
                        dp[ind][canbuy][cap] =
                                   max(-prices[ind] + dp[ind + 1][0][cap],
                                       dp[ind + 1][1][cap]);
                    } else {
                        dp[ind][canbuy][cap] = max(
                                   prices[ind] + dp[ind + 1][1][cap + 1],
                                   dp[ind + 1][0][cap]);
                    }
                }
            }
        }
        return dp[0][1][0];
    }
};