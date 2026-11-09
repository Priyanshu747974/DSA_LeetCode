class Solution {
public:
    int countElements(vector<int>& nums) {
        map<int,int> mpp;
        for(int i =0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        vector<int> ans;
        for(auto it : mpp){
            ans.push_back(it.second);
        }
        int sum=0;
        for(int i = 1;i<ans.size()-1;i++){
            sum+=ans[i];
        }
        return sum;
    }
};