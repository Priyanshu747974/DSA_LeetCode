class Solution {
public:
    int cntSumlessorequal(vector<int>& nums, int goal) {
        int i=0;
        int j=0;
        int sum=0;
        int cnt=0;
        if(goal<0){
            return 0;
        }
        while(j<nums.size()){
            sum=sum+nums[j];
            while(sum>goal){
                sum=sum-nums[i];
                i++;
            }
            cnt=cnt+(j-i+1);
            j++;
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int ans=0; 
        int a=cntSumlessorequal(nums,goal);
        int b=cntSumlessorequal(nums,goal-1);
        ans=a-b;
        return ans;
    }
};