class Solution {
public:
    int solve(int i,vector<int>& nums,int sum, int target,vector<vector<int>> &dp,int &total){
        if(i==nums.size()){
            if(target == sum){
                return 1;
            }
            return 0;
        }
        if(dp[i][sum+total]!=-1){
            return dp[i][sum+total];
        }
        int sumi=solve(i+1,nums,sum+nums[i],target,dp,total);
        int remi=solve(i+1,nums,sum-nums[i],target,dp,total);
        return dp[i][sum+total]=sumi+remi;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> dp(nums.size()+1,vector<int>(2*total+1,-1));
        return solve(0,nums,0,target,dp,total);
    }
};