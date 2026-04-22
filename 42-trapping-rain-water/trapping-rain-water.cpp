class Solution {
public:
/*
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
*/
    int trap(vector<int>& height){
        int n = height.size();
        int l=0;
        int r=n-1;
        int leftmax=0;
        int rightmax=0;
        int ans=0;
        while(l<r){
            leftmax=max(leftmax,height[l]);
            rightmax=max(rightmax,height[r]);
            if(leftmax<rightmax){
                ans=ans+(leftmax-height[l]);
                l++;
            }
            else{
                ans=ans+(rightmax-height[r]);
                r--;
            }
        }
        return ans;
  }
};