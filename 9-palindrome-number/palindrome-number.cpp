class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        if(x == 0) return true;
        vector<int> temp;
        while(x>0){
            temp.push_back(x%10);
            x = x/10;
        }
        int i =0;
        int j =temp.size()-1;
        while(j>i){
            if(temp[i]!=temp[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};