class Solution {
public:
    int function(int i,int j,vector<int>& nums){
        int n = j-i+1;
        if(n==1){
            return nums[i];
        }
        int takeleft = nums[i] - function(i+1,j,nums);
        int takeright = nums[j] - function(i,j-1,nums);

      return max(takeleft,takeright);
    }
    bool predictTheWinner(vector<int>& nums) {
        int diff = function(0,nums.size()-1,nums);
        if(diff>=0){
            return true;
        }
        return false;
    }
};