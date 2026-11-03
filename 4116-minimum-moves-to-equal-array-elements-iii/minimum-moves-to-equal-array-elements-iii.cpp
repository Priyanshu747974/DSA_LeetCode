class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxi = -1;
        for(int i = 0;i<nums.size();i++){
            maxi = max(maxi,nums[i]);
        }
        int moves = 0;
        for(int i =0;i<nums.size();i++){
            moves += abs(nums[i]-maxi);
        }
        return moves;
    }
};