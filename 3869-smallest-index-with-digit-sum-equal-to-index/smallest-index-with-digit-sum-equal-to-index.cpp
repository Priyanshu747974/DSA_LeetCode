class Solution {
public:
    int sum(int n){
        int ans = 0;
        while(n>0){
            ans=ans+n%10;
            n = n/10;
        }
        return ans;
    }
    int smallestIndex(vector<int>& nums) {
        int ans=-1;
        for(int i=0;i<nums.size();i++){
            if(sum(nums[i])==i){
                ans = i;
                break;
            }
        }
        return ans;
    }
};