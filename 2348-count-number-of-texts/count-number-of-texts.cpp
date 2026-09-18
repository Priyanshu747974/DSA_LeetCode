class Solution {
public:
    int mod = 1e9+7;
    int solve(string& s, int i,vector<int>& dp) {
        if (i < 0) {
            return 1;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        long long ans = 0;
        // Take 1 character
        ans += solve(s, i - 1,dp);
        // Take 2 characters
        if (i >= 1 && s[i] == s[i - 1]) {
            ans += solve(s, i - 2,dp);
        }
        // Take 3 characters
        if (i >= 2 && s[i] == s[i - 1] && s[i] == s[i - 2]) {
            ans += solve(s, i - 3,dp);
        }
        if (i >= 3 && (s[i] == '7' || s[i] == '9') && s[i] == s[i - 1] &&
            s[i] == s[i - 2] && s[i] == s[i - 3]) {
            ans += solve(s, i - 4,dp);
        }
        return dp[i]=ans%mod;
    }
    int countTexts(string pressedKeys) {
        vector<int> dp(pressedKeys.size()+1,-1);
        return solve(pressedKeys, pressedKeys.size() - 1,dp);
    }
};