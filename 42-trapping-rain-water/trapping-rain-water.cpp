class Solution {
public:
    vector<int> prefixmax(vector<int> arr){
        int n=arr.size();
        vector<int>pmax(n);
        pmax[0]=arr[0];
        for(int i=1;i<n;i++){
            pmax[i]=max(pmax[i-1],arr[i]);
        }
        return pmax;
    }
    vector<int> suffixmax(vector<int> arr){
        int n=arr.size();
        vector<int>smax(n);
        smax[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--){
            smax[i]=max(smax[i+1],arr[i]);
        }
        return smax;
    }
    int trap(vector<int>& height) {
        int ans=0;
        vector<int> pmax=prefixmax(height);
        vector<int> smax=suffixmax(height);
        for(int i=0;i<height.size();i++){
            int leftmax = pmax[i];
            int rightmax = smax[i];
            ans=ans+min(leftmax,rightmax)-height[i];
        }
        return ans;
    }
};