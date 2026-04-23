class Solution {
public:
    vector<int> NextSmallest(vector<int>& arr){
        int n=arr.size();
        stack<int> st;
        vector<int> nse(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[i] <= arr[st.top()]){
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
    vector<int> PrevSmallest(vector<int>& arr){
        int n=arr.size();
        stack<int> st;
        vector<int> pse(n);
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[i] < arr[st.top()]){
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
    vector<int> Nextgreatest(vector<int>& arr){
        int n=arr.size();
        stack<int> st;
        vector<int> nge(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[i] >= arr[st.top()]){
                st.pop();
            }
            if(st.empty()){
                nge[i]=n;
            }
            else{
                nge[i]=st.top();
            }
            st.push(i);
        }
        return nge;
    }
    vector<int> PrevGreatest(vector<int>& arr){
        int n=arr.size();
        stack<int> st;
        vector<int> pge(n);
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[i] > arr[st.top()]){
                st.pop();
            }
            if(st.empty()){
                pge[i]=-1;
            }
            else{
                pge[i]=st.top();
            }
            st.push(i);
        }
        return pge;
    }
    long long subArrayRanges(vector<int>& nums) {
        long long sum=0;
        long long minsum=0;
        long long maxsum=0;
        vector<int> pse=PrevSmallest(nums);
        vector<int> nse=NextSmallest(nums);
        vector<int> pge=PrevGreatest(nums);
        vector<int> nge=Nextgreatest(nums);
        for(int i=0;i<nums.size();i++){
            int ls = i-pse[i];
            int rs = nse[i]-i;
            int lg = i-pge[i];
            int rg = nge[i]-i;
            minsum += (long long)ls * rs * nums[i];
            maxsum += (long long)lg * rg * nums[i];
        }
        sum=maxsum-minsum;
        return sum;
    }
};