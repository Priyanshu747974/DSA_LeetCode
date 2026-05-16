class Solution {
public:
    int maxlength = INT_MIN;
    int length=0;
    int longestOnes(vector<int>& nums, int k) {
        int i=0;
        int j=0;
        int zeros=0;
        while(j<nums.size()){
            if(nums[j]==0){
                zeros++;
            }
            while(zeros>k){
                if(nums[i]==0){
                    zeros--;
                }
                i++;
            }
            j++;
            length=j-i;
            maxlength = max(length,maxlength);
        }
        return maxlength;  
    }
};