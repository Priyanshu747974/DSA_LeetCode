class Solution {
public:
    vector<vector<int>>ans;
    void function(int i,int target,int k,vector<int>ds,vector<int>&arr,int n){
        if (target < 0 || ds.size() > k) return;
        if (target==0){
            if(ds.size()==k){
                ans.push_back(ds);
            }
            return;
        }
        if(i==n){
            return;
        }
        ds.push_back(arr[i]);    
        function(i+1,target-arr[i],k,ds,arr,n);
        ds.pop_back();

        function(i+1,target,k,ds,arr,n);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector <int> arr={1,2,3,4,5,6,7,8,9};
        vector<int>ds;
        function(0,n,k,ds,arr,9);
        return ans;
    }
};