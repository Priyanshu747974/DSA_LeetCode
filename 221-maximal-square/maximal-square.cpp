class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int maxsize = 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (matrix[r][c] == '1') {
                    if (r == 0 || c == 0) {
                        dp[r][c] = 1;
                    }
                    else {
                        dp[r][c] = 1 + min({dp[r - 1][c], dp[r][c - 1],
                                            dp[r - 1][c - 1]});
                    }
                }

                maxsize = max(maxsize, dp[r][c]);
            }
        }
        return maxsize * maxsize;
    }
};