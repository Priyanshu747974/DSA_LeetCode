class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int  mid = n/2;
        int moves = 0;
        for(int i = 0;i<nums.size();i++){
            moves+= abs(nums[mid]-nums[i]);
        }
        return moves;
    }
};