class Solution {
public:
    int function(int ind, int prev, vector<int>& nums,
                 vector<vector<int>>& dp) {
        if (ind >= nums.size()) {
            return 0;
        }
        if (dp[ind][prev + 1] != -1) {
            return dp[ind][prev + 1];
        }
        int notTake = function(ind + 1, prev, nums, dp);

        int take = 0;
        if (prev == -1 || nums[ind] % nums[prev] == 0) {
            take = 1 + function(ind + 1, ind, nums, dp);
        }

        return dp[ind][prev + 1] = max(take, notTake);
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        function(0, -1, nums, dp);
        vector<int> ans;

        int ind = 0;
        int prev = -1;

        while (ind < n) {
            int notTake = function(ind + 1, prev, nums, dp);

            int take = -1;
            if (prev == -1 || nums[ind] % nums[prev] == 0) {
                take = 1 + function(ind + 1, ind, nums, dp);
            }

            if (take >= notTake) {
                ans.push_back(nums[ind]);
                prev = ind;
            }

            ind++;
        }

        return ans;
    }
};