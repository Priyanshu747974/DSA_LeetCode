class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_map<char,int> mpp;
        char ans = '$';
        for(int i =0;i<s.size();i++){
            mpp[s[i]]++;
            if(mpp[s[i]]==2){
                ans = s[i];
                break;
            }
        }
        return ans;
    }
};