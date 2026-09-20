class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi = nums[0];
        int mini = nums[0];
        int ans = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int x = nums[i];

            int a = x;
            int b = maxi * x;
            int c = mini * x;

            maxi = max(a, max(b, c));
            mini = min(a, min(b, c));

            ans = max(ans, maxi);
        }

        return ans;
    }
};