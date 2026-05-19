class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mpp;
        for(int i=0;i<t.size();i++){
            mpp[t[i]]++;
        }
        int minlen=INT_MAX;
        int i=0;
        int cnt=0;
        int sind=-1;
        for(int j=0;j<s.size();j++){
            if(mpp[s[j]]>0){
                cnt++;
            }
            mpp[s[j]]--;
            while(cnt==t.size()){
                if(minlen>j-i+1){
                    minlen=j-i+1;
                    sind=i;
                }
                mpp[s[i]]++;
                if(mpp[s[i]]>0){
                    cnt--;
                }
                i++;
            }
        }
        if(sind==-1) return "";
        return s.substr(sind,minlen);
    }
};