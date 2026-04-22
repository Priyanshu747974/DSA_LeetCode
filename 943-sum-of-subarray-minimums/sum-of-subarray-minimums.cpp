class Solution {
public:
   vector<int>nextsmaller(vector<int> &arr){
    int n=arr.size();
    vector<int> nse(n);
    stack<int> st;
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
   vector<int>prevsmaller(vector<int> &arr){
    int n=arr.size();
    vector<int> psee(n);
    stack<int> st;
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[i]<arr[st.top()]){
            st.pop();
        }
        if(st.empty()){
            psee[i]=-1;
        }
        else{
            psee[i]=st.top();
        }
        st.push(i);
    }
    return psee;
   }
   int sumSubarrayMins(vector<int>& arr) {
    vector<int> nse= nextsmaller(arr);
    vector<int> psee= prevsmaller(arr);
    int n= arr.size();
    long long target=0;
    int mod=1e9+7;
    for(int i=0;i<n;i++){
        long long  left= nse[i]-i;
        long long right= i-psee[i];
        target=(target+(left*right %mod * arr[i] %mod ) %mod ) %mod;
    }
    return target;
    }
};