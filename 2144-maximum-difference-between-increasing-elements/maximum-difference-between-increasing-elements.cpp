class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int mini=nums[0];
        int Maxdiff=0;
        int n= nums.size();
        for(int i=0;i<n;i++){
            int diff= nums[i]-mini;
            Maxdiff =max(Maxdiff,diff);
            mini=min(mini,nums[i]);
        }
        if(Maxdiff>0){
            return Maxdiff;
        }
        return -1;
    }
};