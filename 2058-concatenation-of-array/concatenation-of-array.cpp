class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans(nums.size());
        for(int i= 0;i<nums.size();i++){
            ans[i]=nums[i];
        }
        for(int j= 0;j<nums.size();j++){
            ans.push_back(nums[j]);
        }
        return ans;
    }
};