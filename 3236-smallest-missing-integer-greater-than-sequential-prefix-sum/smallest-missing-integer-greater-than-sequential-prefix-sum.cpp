class Solution {
public:
    bool check(int n, vector<int>& arr){
        for(int j =0;j<arr.size();j++){
            if(n == arr[j]){
                return true;
            }
        }
        return false;
    }
    int missingInteger(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0]+1;
        }
        int lastindex = 0;
        int sum = nums[0];
        for(int i =1;i<nums.size();i++){
            if(nums[i]==nums[i-1]+1){
                sum += nums[i];
            }
            else{
                lastindex = i;
                break;
            }
        }
        vector<int> arr(nums.begin()+lastindex,nums.end());
        int ans=0;
        int i =0;
        if(sum==nums[0] && check(sum,arr)==false){
            for(int i=1;i<50;i++){
                if(check(sum+i,arr)==false){
                    return sum+i;
                    break;
                }
            }
           return sum+1;
        }
        while(i<arr.size()){
            if(check(sum,arr)==false){
                ans = sum;
                return ans;
            }
            i++;
            sum++;
        }
        return ans;
    }
};