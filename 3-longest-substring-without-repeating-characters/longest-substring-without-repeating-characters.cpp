class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0;
        int j=0;
        int length=0;
        set<char> st;
        while(j<s.size()){
            if(st.find(s[j])==st.end()){
                st.insert(s[j]);
                length=max(length,j-i+1);
                j++;
            }
            else{
                st.erase(s[i]);
                i++;
            }
        }
        return length;
    }
};