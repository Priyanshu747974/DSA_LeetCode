class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nge(nums2.size());
        stack<int> st;
        unordered_map<int,int>mpp;
        for(int i = nums2.size() - 1; i >= 0; i--){
            while(!st.empty() && nums2[i]>=st.top()){
                st.pop();
            }
            if(st.empty()){
                nge[i]=-1;
            }
            else{
                nge[i]=st.top();
            }
            st.push(nums2[i]);
        }
        for(int i=0; i< nums2.size();i++){
            mpp[nums2[i]]=nge[i];
        }
        vector<int>ans;
        for(int i=0;i<nums1.size();i++){
            ans.push_back(mpp[nums1[i]]);
        }
        return ans;
    }
};