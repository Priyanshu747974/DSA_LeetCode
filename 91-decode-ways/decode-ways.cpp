class Solution {
public:
    /*
        int solve(string& s, int i, vector<int>& dp) {
            if (i == s.size()) {
                return 1;
            }
            if (s[i] == '0') {
                return 0;
            }
            if (dp[i] != -1) {
                return dp[i];
            }
            int result = solve(s, i + 1, dp);
            if (i < s.size() - 1) {
                if (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6')) {
                    result += solve(s, i + 2, dp);
                }
            }
            return dp[i] = result;
        }*/
    int numDecodings(string s) {
        vector<int> dp(s.size()+1, 0);
        dp[s.size()]=1;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '0') {
                dp[i] = 0;
            } else {
                dp[i] = dp[i + 1];
                if (i < s.size() - 1) {
                    if (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6')) {
                        dp[i] += dp[i + 2];
                    }
                }
            }
        }
        return dp[0];
    }
};