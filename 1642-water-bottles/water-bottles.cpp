class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;
        while(numBottles >= numExchange){
            int n = numBottles/numExchange;
            int rem = numBottles % numExchange;
            ans +=n;
            numBottles=n+rem;
            
        }
        return ans;
    }
};