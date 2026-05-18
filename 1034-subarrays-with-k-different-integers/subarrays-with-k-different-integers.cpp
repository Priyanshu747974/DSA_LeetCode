class Solution {
public:
    int function(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> hashmap;
        int i=0;
        int j=0;
        int cnt=0;
        if(k<0){
            return 0;
        }
        while(j<n){
            hashmap[nums[j]]++;
            while(hashmap.size()>k){
                hashmap[nums[i]]--;
                if(hashmap[nums[i]]==0){
                    hashmap.erase(nums[i]);
                }
                i++;
            }
            cnt=cnt+(j-i+1);
            j++;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k){
        int ans=0;
        int a=function(nums,k);
        int b=function(nums,k-1);
        ans=a-b;
        return ans;
    }
};