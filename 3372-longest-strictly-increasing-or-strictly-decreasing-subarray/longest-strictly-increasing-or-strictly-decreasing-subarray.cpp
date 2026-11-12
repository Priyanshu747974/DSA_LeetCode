class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int longestINC = 1;
        int longestDEC = 1;

        int i = 0, j = 1;

        // Strictly increasing
        while (j < n) {
            if (nums[j] > nums[j-1]) {
                longestINC = max(longestINC, j-i+1);
            }
            else {
                i = j;
            }
            j++;
        }

        int p = 0, q = 1;

        // Strictly decreasing
        while (q < n) {
            if (nums[q] < nums[q-1]) {
                longestDEC = max(longestDEC, q-p+1);
            }
            else {
                p = q;
            }
            q++;
        }

        return max(longestINC, longestDEC);
    }
};