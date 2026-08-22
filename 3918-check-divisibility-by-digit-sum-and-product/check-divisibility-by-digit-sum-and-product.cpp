class Solution {
public:
    int nsum(int n){
        int ans = 0;
        while(n!=0){
            ans+=n%10;
            n=n/10;
        }
        return ans;
    }
    int nprod(int n){
        int ans = 1;
        while(n!=0){
            ans=ans*(n%10);
            n=n/10;
        }
        return ans;
    }
    bool checkDivisibility(int n) {
        int sum = nsum(n);
        int prod = nprod(n);
        if(n%(sum+prod)==0){
            return true;
        }
        return false;
    }
};