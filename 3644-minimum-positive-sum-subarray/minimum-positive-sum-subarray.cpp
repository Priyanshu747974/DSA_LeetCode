class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        multimap<int,int> mpp;

        for(int i = 0; i < nums.size(); i++) {
            int sum = 0;

            for(int j = i; j < nums.size(); j++) {
                sum += nums[j];
                mpp.insert({j - i + 1, sum});
            }
        }

        int ans = INT_MAX;

        for(auto it : mpp) {
            if(it.first >= l && it.first <= r && it.second > 0) {
                ans = min(it.second, ans);
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};