class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        vector<int> temp(1,0);
        while(x>0){
            temp.push_back(x%10);
            x = x/10;
        }
        temp.push_back(0);
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