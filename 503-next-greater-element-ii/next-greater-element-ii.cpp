class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack <int> st;
        int n= nums.size();
        vector<int> nge(n);
        for(int i=2*n-1;i>=0;i--){
            int ind=i%n;
            while(!st.empty() && nums[ind]>=st.top()){
                st.pop();
            }
            if(st.empty()){
                if(i<n){
                    nge[ind]=-1;
                }
            }
            else{
                if(i<n){
                    nge[ind]=st.top();
                }
            }
            st.push(nums[ind]);
        }
        return nge;
    }
};