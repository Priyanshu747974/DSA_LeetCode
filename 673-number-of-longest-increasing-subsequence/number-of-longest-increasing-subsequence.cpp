class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1);
        vector<int> cnt(n,1);
        int maxi = 0;
        for(int ind = 0; ind<n; ind++){
            for(int prev = 0; prev<ind ; prev++){
                if(nums[ind]>nums[prev] && dp[ind]<dp[prev]+1){
                    dp[ind]=1+dp[prev];
                    cnt[ind]=cnt[prev];
                }
                else if(nums[ind]>nums[prev] && dp[ind]==dp[prev]+1){
                    cnt[ind]+=cnt[prev];
                }
            }
            maxi = max(maxi , dp[ind]);
        }
        int ans = 0;
        for(int i = 0; i<n;i++){
            if(dp[i]==maxi){
                ans+=cnt[i];
            }
        }
        return ans;
    }
};