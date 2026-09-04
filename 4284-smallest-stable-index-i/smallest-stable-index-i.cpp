class Solution {
public:
    int maxi(vector<int>& nums, int i){
        int maxi = INT_MIN;
        for(int j=0;j<=i;j++){
            maxi = max(maxi,nums[j]);
        }
        return maxi;
    }
    int mini(vector<int>& nums, int i){
        int mini = INT_MAX;
        for(int j=i;j<nums.size();j++){
            mini = min(mini,nums[j]);
        }
        return mini;
    }
    int firstStableIndex(vector<int>& nums, int k) {
        vector<int> instability;
        int ans = -1;
        for(int i =0;i<nums.size();i++){
            instability.push_back(maxi(nums,i)-mini(nums,i));
        }
        for(int i=0;i<instability.size();i++){
            if(instability[i]<=k){
                ans = i;
                break;
            }
        }
        return ans;
    }
};