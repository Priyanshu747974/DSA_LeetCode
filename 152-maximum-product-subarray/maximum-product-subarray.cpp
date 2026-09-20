class Solution {
public:
    int solve(int i, vector<int>& nums, long long curr,
              vector<unordered_map<int, int>>& dp) {

        if (i == nums.size()) {
            return curr;
        }

        if (dp[i].count(curr)) {
            return dp[i][curr];
        }

        long long product = solve(i + 1, nums, curr * nums[i], dp);
        long long leave = solve(i + 1, nums, nums[i], dp);

        return dp[i][curr] = max(curr, max(product, leave));
    }

    int maxProduct(vector<int>& nums) {
        vector<unordered_map<int, int>> dp(nums.size());

        return solve(1, nums, nums[0], dp);
    }
};