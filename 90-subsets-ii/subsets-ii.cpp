class Solution {
public:
    vector<vector<int>> ans;
    void function(int i,vector<int>ds,vector<int>& nums,int n){
        if(i==n){
            ans.push_back(ds);
            return;
        }
        ds.push_back(nums[i]);
        function(i+1,ds,nums,n);
        ds.pop_back();
        int j=i;
        while(j+1<n && nums[j]==nums[j+1]){
            j++;
        }
        function(j+1,ds,nums,n);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();
        vector<int> ds;
        sort(nums.begin(),nums.end());
        function(0,ds,nums,n);
        return ans;
    }
};