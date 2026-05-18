class Solution {
public:
    int oddcntlessorequal(vector<int>& nums, int k) {
        int i=0;
        int j=0;
        int oddcnt=0;
        int cnt=0;
        if(k<0){
            return 0;
        }
        while(j<nums.size()){
            if(nums[j]%2!=0){
                oddcnt++;
            }
            while(oddcnt>k){
                if(nums[i]%2!=0){
                    oddcnt--;
                }
                i++;
            }
            cnt=cnt+(j-i+1);
            j++;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        int ans=0;
        int a=oddcntlessorequal(nums,k);
        int b=oddcntlessorequal(nums,k-1);
        ans=a-b;
        return ans;
    }
};