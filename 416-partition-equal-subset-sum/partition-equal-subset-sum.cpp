class Solution {
public:
    bool function(int ind, int sum, vector<int>& nums,vector<vector<int>>& dp){
        if(sum == 0){
            return true;
        }
        if(sum < 0) return false;
        if(ind == 0) return nums[0] == sum;
        if(dp[ind][sum]!=-1){
            return dp[ind][sum];
        }
        bool take = false;
            if (nums[ind] <= sum)
            take = function(ind-1, sum-nums[ind], nums, dp);
        bool not_take = function(ind-1, sum, nums,dp);

        return dp[ind][sum] = take || not_take;
    }
    bool canPartition(vector<int>& nums) {
        int sum =0;
        int n =nums.size();
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        vector<vector<int>> dp(n,vector<int>(sum/2 +1,-1));
        if(sum%2 !=0){
            return false;
        }
        else{
            return function(n-1,sum/2,nums,dp);
        }
        return true;
    }
};