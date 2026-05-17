class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0;
        int cnt=0;
        map<int,int >mpp;
        mpp[0]=1;
        for(int i=0;i<nums.size();i++){
            sum=sum+nums[i];
            if(mpp.find(sum-k)!=mpp.end()){
                cnt=cnt+mpp[sum-k];
            }
            mpp[sum]++;   
        }
        return cnt;
    }
};