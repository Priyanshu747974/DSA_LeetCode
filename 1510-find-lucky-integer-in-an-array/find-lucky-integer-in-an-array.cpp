class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> mpp;
        for(int i=0;i<arr.size();i++){
            mpp[arr[i]]++;
        }
        int ans = -1;
        for(auto it: mpp){
            if(it.first==it.second){
                ans = max(ans,it.first);
            }
        }
        return ans;
    }
};