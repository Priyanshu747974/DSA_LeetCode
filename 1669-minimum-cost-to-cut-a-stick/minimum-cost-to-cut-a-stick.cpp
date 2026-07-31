class Solution {
public:
    int f(int i, int j, vector<int>& cuts, vector<vector<int>>& dp) {

        if (i > j)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = 1e9;

        for (int k = i; k <= j; k++) {

            int cost = f(i, k - 1, cuts, dp) + f(k + 1, j, cuts, dp) +
                       cuts[j + 1] - cuts[i - 1];

            ans = min(ans, cost);
        }

        return dp[i][j] = ans;
    }
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        vector<vector<int>> dp(cuts.size(), vector<int>(cuts.size(), -1));
        return f(1,cuts.size()-2, cuts, dp);
    }
};