class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<int> n;
        for(int i=0;i<nums.size();i++){
            n.push_back(nums[i]*nums[i]);
        }
        sort(n.begin(),n.end());
        long long sum = 0;
        for(int i = 0;i<n.size()/2;i++){
            sum = sum-n[i];
        }
        for(int i = n.size()/2;i<n.size();i++){
            sum = sum+n[i];
        }
        return sum;
    }
};