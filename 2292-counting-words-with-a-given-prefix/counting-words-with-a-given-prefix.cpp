class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int cnt =0;
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words[i].size();j++){
                if(pref[j]!=words[i][j]){
                    break;
                }
                else if(j==pref.size()-1){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};