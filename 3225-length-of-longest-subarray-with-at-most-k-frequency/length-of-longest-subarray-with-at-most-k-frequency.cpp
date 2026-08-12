class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        map<int, int> mpp;
        if (nums.size() == 0) {
            return 0;
        }
        int i = 0;
        int j = 0;
        int ans = j - i + 1;
        while (j < nums.size() && i <= j) {
            mpp[nums[j]]++;
                while (mpp[nums[j]] > k){
                    mpp[nums[i]]--;
                    i++;
                }
            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};