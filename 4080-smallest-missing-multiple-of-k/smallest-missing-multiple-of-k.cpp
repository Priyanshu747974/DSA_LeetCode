class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        for(int i =0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        int ans;
        int i =1;
        while(i<=101){
            if(mpp[k*i]==0){
                ans = k*i;
                break;
            }
            i++;
        }
        
        return ans;
    }
};