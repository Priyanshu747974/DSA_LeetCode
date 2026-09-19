class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        vector<int> prefixMax(nums.size());
        int maxi=-1;
        for(int i=0;i<nums.size();i++){
            maxi=max(maxi,nums[i]);
            prefixMax[i]=maxi;
        }
        vector<int> suffixMin(nums.size());
        int mini=1e9;
        for(int i=nums.size()-1;i>=0;i--){
            mini=min(mini,nums[i]);
            suffixMin[i]=mini;
        }
        int ans = 0;
        for(int i =1;i<nums.size()-1;i++){
            int beauty = 0;
            if(nums[i]>prefixMax[i-1] && nums[i]<suffixMin[i+1]){
                beauty = 2;
            }
            else if(nums[i-1]<nums[i] && nums[i]<nums[i+1]){
                beauty = 1;
            }
            ans += beauty;
        }
        return ans;
    }
};