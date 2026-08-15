class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int sum = nums[0];
        long long a = nums[0];
        for(int i = 1;i<n;i++){
            sum ^= nums[i];
            a+=nums[i];
        }
        if(a==0) return 0;
        if(sum!=0 ){
            return n;
        }else{
            return n-1;
        }
        
    }
};