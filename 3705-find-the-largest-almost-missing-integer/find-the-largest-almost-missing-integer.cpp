class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> freq;

        for (int x : nums) {
            freq[x]++;
        }

        int ans = -1;

        if (k == n) {
            for (int x : nums) {
                ans = max(ans, x);
            }
        }
        else if (k == 1) {
            for (auto &[x, f] : freq) {
                if (f == 1) {
                    ans = max(ans, x);
                }
            }
        }
        else {
            if (freq[nums[0]] == 1)
                ans = max(ans, nums[0]);

            if (freq[nums[n - 1]] == 1)
                ans = max(ans, nums[n - 1]);
        }

        return ans;
    }
};