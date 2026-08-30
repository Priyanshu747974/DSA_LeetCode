class Solution {
public:
Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }
    int minimumDeletions(vector<int>& nums) {
        int maxi = INT_MIN;
        int mini = INT_MAX;
        int n = nums.size();
        for(int i =0;i<nums.size();i++){
            maxi= max(maxi,nums[i]);
            mini= min(mini,nums[i]);
        }
        int xi=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==maxi){
                xi=i;
            }
        }
        int ni=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==mini){
                ni=i;
            }
        }
        int ans1 = max(xi, ni) + 1;      
        int ans2 = n - min(xi, ni);      
        int ans3 = xi + 1 + (n - ni);     
        int ans4 = ni + 1 + (n - xi);     

        return min({ans1, ans2, ans3, ans4});
    }
};