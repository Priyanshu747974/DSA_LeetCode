class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int lastIndex = 0;
        sort(nums.begin(), nums.end());
        vector<int> dp(nums.size(), 1);
        vector<int> hash(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            hash[i] = i;
        }
        for (int ind = 0; ind < nums.size(); ind++) {
            for (int prev = 0; prev < ind; prev++) {
                if (nums[ind] % nums[prev] == 0 && dp[prev] + 1 > dp[ind]) {
                    dp[ind] = dp[prev] + 1;
                    hash[ind] = prev;
                }
            }
            if (dp[ind] > dp[lastIndex]) {
                lastIndex = ind;
            }
        }
        vector<int> ans;
        ans.push_back(nums[lastIndex]);
        while (hash[lastIndex] != lastIndex) {
            lastIndex = hash[lastIndex];
            ans.push_back(nums[lastIndex]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};