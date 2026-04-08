class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n= strs.size();
        string longest=strs[0];
        for(int i=1;i<n;i++){
            int j=0;
            int k=strs[i].size();
            while(j<k && j<longest.size() 
                        && longest[j]==strs[i][j]){
                j++;
             }
             longest=longest.substr(0,j);
             if(longest=="")return "";
        }
        return longest;
    }
};