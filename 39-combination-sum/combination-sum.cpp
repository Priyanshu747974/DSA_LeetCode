class Solution {
public:
    vector<vector<int>> ans;
    void function(int i,int target,vector<int> ds,vector<int>& arr,int n){
            if(target==0){
                ans.push_back(ds);
                return;
            }
            if(i==n){
            return;
            }
        
        if(target-arr[i]>=0){
            ds.push_back(arr[i]);
            function(i,target-arr[i],ds,arr,n);
            ds.pop_back();
        }
        function(i+1,target,ds,arr,n);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> ds;
        function(0,target,ds,candidates,candidates.size());
        return ans;
    }
};