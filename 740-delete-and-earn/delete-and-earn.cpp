class Solution {
public:
    int solve(vector<int>& nums, int i,vector<int>& dp){
        if(i==0){
            return nums[0];
        }
        if(i<0){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        
        int take = nums[i]+solve(nums,i-2,dp);
        int notake = solve(nums,i-1,dp);
        return dp[i]=max(take, notake);
    }
    int deleteAndEarn(vector<int>& nums) {
        
        int mx = 0;
        for (int x : nums) {
            mx = max(mx, x);
        }
        vector<int> points(mx+1,0);
        vector<int> dp(points.size(),-1);
        for(auto it: nums){
            points[it]+= it;
        }
        return solve(points,points.size()-1,dp);
    }
};