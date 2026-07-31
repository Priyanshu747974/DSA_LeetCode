class Solution {
public:
    int f(int i, int j, vector<vector<int>>& dp, vector<int>& nums) {

        if (i>j)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = INT_MIN;

        for (int k = i; k <= j; k++) {

            int cost = f(i, k-1, dp,nums) + f(k + 1, j,dp , nums) + nums[i-1]*nums[k]*nums[j+1];

            ans = max(ans, cost);
        }

        return dp[i][j] = ans;
    }
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>> dp(nums.size()+2,vector<int>(nums.size()+2,-1));
        return f(1,nums.size()-2,dp,nums);
    }
};