class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long cnt =0;
        long long length = 1;
        int j=0;
        while(j<prices.size()-1){
            if(prices[j]-prices[j+1]==1){
                j++;
                length ++;
            }
            else{
                j++;
                length =1;
            }
            cnt = cnt+length;
        }
        return cnt+1;
    }
};