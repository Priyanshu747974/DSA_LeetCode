class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int>nge;
        for(int i=0;i<nums.size();i++){
            int next=-1;
            for(int j=i+1;j<=i+nums.size()-1;j++){
                int ind= j%nums.size();
                if(nums[ind]>nums[i]){
                    next=nums[ind];
                    break;
                }
            }
            nge.push_back(next);
        }
        return nge;
    }
};