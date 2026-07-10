class Solution {
public:
    int function(int ind, vector<int>& nums, vector<int>&dp){
        int n = nums.size();
        if (ind == 0){
            return nums[0];
        }
        if(ind<0){
            return 0;
        }    
        if(dp[ind]!= -1){
            return dp[ind];
        }
        int pick = nums[ind]+ function(ind-2,nums,dp);
        int not_pick = function(ind-1,nums,dp);

        return dp[ind]=max(pick, not_pick);
    }
    int rob(vector<int>& nums){
        int n = nums.size();
        if(n==1){
            return nums[0];
        }
        vector<int> nums1;
        vector<int> nums2;
        for(int i=0;i<n;i++){
            if(i!=0){
                nums1.push_back(nums[i]);
            }
            if(i!=n-1){
                nums2.push_back(nums[i]);
            }
        }
        vector<int> dp1(nums1.size(),-1);
        vector<int> dp2(nums2.size(),-1);
        int ans1 = function(nums1.size()-1,nums1,dp1);
        int ans2 = function(nums2.size()-1,nums2,dp2);

        return max(ans1,ans2);
    }
};