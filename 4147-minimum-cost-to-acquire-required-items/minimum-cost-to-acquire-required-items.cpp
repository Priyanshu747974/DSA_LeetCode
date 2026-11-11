class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long ans1 = 1LL*need1*cost1 + 1LL*need2*cost2;
        long long ans2 = 1LL*max(need1 , need2)*costBoth;
        int both = min(need1, need2);
        int rem1 = need1 - both;
        int rem2 = need2 - both;
        long long ans3 = 1LL * both * costBoth
               + 1LL * rem1 * cost1
               + 1LL * rem2 * cost2;
        return min({ans1,ans2,ans3});
    }
};