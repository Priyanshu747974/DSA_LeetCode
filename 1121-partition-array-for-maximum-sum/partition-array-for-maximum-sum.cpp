class Solution {
public:
    int f(int i, vector<int>& arr, int k, vector<int>& dp) {

        if (i==arr.size())
            return 0;

        if (dp[i]!= -1)
            return dp[i];

        int ans = INT_MIN;
        int len = 0;
        int maxi = INT_MIN;
        int n = arr.size();
        for (int ind = i; ind <= min(n-1,i+k-1); ind++) {
            len++;
            maxi = max(maxi, arr[ind]);
            int cost = f(ind + 1, arr, k,dp) + len*maxi;

            ans = max(ans, cost);
        }

        return dp[i] = ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size(),-1);
        return f(0,arr,k,dp);
    }
};