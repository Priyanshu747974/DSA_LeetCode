class Solution {
public:
    int mod = 1e9 + 7;

    int function(int i, vector<int>& arr, int parity, vector<vector<int>>& dp) {
        
        if(i == arr.size()) {
            return 0;
        }

        if(dp[i][parity] != -1) {
            return dp[i][parity];
        }

        int newParity = (parity + arr[i]) % 2;

        int ans = 0;

        if(newParity == 1) {
            ans = 1;
        }

        return dp[i][parity] = (ans + function(i+1, arr, newParity, dp)) % mod;
    }

    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();

        vector<vector<int>> dp(n, vector<int>(2, -1));

        int ans = 0;

        for(int i = 0; i < n; i++) {
            ans = (ans + function(i, arr, 0, dp)) % mod;
        }

        return ans;
    }
};