class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi =-1e9;
        for(int i=0;i<nums.size();i++){
            for(int j =0;j<nums.size();j++){
                if(i==j)continue;
                maxi = max(maxi,(nums[i]-1)*(nums[j]-1));
            }
        }
        return maxi;
    }
};