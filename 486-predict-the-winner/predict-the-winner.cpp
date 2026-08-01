class Solution {
public:
    int function(int i,int j,vector<int>& nums, vector<vector<int>>& dp){
        int n = j-i+1;
        if(n==1){
            return nums[i];
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int takeleft = nums[i] - function(i+1,j,nums,dp);
        int takeright = nums[j] - function(i,j-1,nums,dp);

      return dp[i][j]=max(takeleft,takeright);
    }
    bool predictTheWinner(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size(),-1));
        int diff = function(0,nums.size()-1,nums,dp);
        if(diff>=0){
            return true;
        }
        return false;
    }
};