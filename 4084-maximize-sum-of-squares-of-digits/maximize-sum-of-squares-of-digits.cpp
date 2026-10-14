class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > 9 * num) return "";
        vector<int> v(num,0);
        int have = sum;
        int i =0;
        while(have>=9){
            v[i]=9;
            have = have - 9;
            i++;
            
        }
        if (i < num) {
            v[i] = have;
        }
        string s =  "";
        for(int x:v){
            s += to_string(x);
        }
        return  s;
    }
};