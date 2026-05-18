class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n= cardPoints.size();
        int i=0;
        int j=0;
        int ans=0;
        int sum=0;
        int total=0;
        for(int i=0;i<n;i++){
            total=total+cardPoints[i];
        }
        while(j<n){
            sum=sum+cardPoints[j];
           if((j-i+1)>(n-k)){
                sum=sum-cardPoints[i];
                i++;
           }
           if((j-i+1)==(n-k)){
                ans=max(ans,(total-sum));
           }
           j++;
        }
        return ans;
    }
};