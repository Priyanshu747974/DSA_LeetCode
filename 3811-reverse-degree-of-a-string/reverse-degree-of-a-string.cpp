class Solution {
public:
    int reverseDegree(string s) {
        vector<int>v(26);
        for(int i=0;i<26;i++){
            v[i]=26-i;
        }
        unordered_map<char,int> mpp;
        
        for(char i='a';i<='z';i++){
            mpp[i]=i-'a';
        }
        int ans= 0;
        for(int i=0;i<s.size();i++){
            ans+=v[mpp[s[i]]]*(i+1);
        }
        return ans;
    }
};