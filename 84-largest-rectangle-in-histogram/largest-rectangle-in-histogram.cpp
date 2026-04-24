class Solution {
public:
    int maximum(vector<int> arr){
        int maxi=INT_MIN;
        for(int i=0;i<arr.size();i++){
            maxi=max(maxi,arr[i]);
        }
        return maxi;
    }
    vector<int> nextsmallest(vector<int> &arr){
        int n =arr.size();
        stack<int> st;
        vector<int> nse(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[i]<=arr[st.top()]){
                st.pop();
            }
            if(st.empty()){
                nse[i]=n;
            }
            else{
                nse[i]=st.top();
            }
            st.push(i);
        }
        return nse;
    }
    vector<int> prevsmallest(vector<int> &arr){
        int n =arr.size();
        stack<int> st;
        vector<int> pse(n);
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[i]<=arr[st.top()]){
                st.pop();
            }
            if(st.empty()){
                pse[i]=-1;
            }
            else{
                pse[i]=st.top();
            }
            st.push(i);
        }
        return pse;
    }
    int largestRectangleArea(vector<int>& heights) {
        int area=0;
        int n=heights.size();
        vector<int>left=prevsmallest(heights);
        vector<int>right=nextsmallest(heights);
        int ans=0;
        for(int i=0;i<n;i++){
            int width =right[i]-left[i]-1;
            area=width*heights[i];
            ans=max(area,ans);
        }
        return ans;
    }
};