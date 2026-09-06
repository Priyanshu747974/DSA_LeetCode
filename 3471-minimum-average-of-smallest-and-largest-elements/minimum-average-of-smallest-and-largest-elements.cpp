class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i =0;
        int j =nums.size()-1;
        double ans = 1000;
        while(j>=i){
            double avg = (nums[i]+nums[j])/2.0;
            i++;
            j--;
            ans = min(avg,ans);
        }
        return ans;
    }
};