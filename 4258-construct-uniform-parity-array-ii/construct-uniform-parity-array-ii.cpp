class Solution {
public:
    bool alleven(vector<int>& nums1){
        bool ans = true;
        for(int i =0;i<nums1.size();i++){
            if(nums1[i]%2!=0){
                ans = false;
            }
        }
        return ans;
    }
    bool uniformArray(vector<int>& nums1) {
        bool ans = true;
        int mini = INT_MAX;
        for(int i =0;i<nums1.size();i++){
            if(nums1[i]%2!=0){
                mini = min(mini,nums1[i]);
            }
        }
        if(alleven(nums1)){
            return true;
        }
        for(int i =0;i<nums1.size();i++){
            if(nums1[i]%2!=0){
                continue;
            }
            else if(nums1[i]>mini){
                continue;
            }
            else{
                ans = false;
            }
        }
        return ans;
    }
};