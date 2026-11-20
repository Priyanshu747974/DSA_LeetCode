class Solution {
public:
    int function(int num){
        int ans = 0;
        while(num>0){
            ans=ans + num%10;
            num = num/10;
        }
        return ans;
    }
    int addDigits(int num) {
        int ans = function(num);
        while(ans>=10){
            ans = function(ans);
        }
        return ans;
    }
};