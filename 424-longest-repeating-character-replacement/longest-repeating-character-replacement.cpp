class Solution {
public:
    int getMax(vector<int>& v){
        int maxi = 0;
        for(int i = 0; i < 26; i++){
            maxi = max(maxi, v[i]);
        }
       return maxi;
    }
    int characterReplacement(string s, int k) {
        int length=0;
        int i=0;
        int j=0;
        int maxlength=INT_MIN;
        vector<int> v(26);
        while(j<s.size()){
            v[s[j]-'A']++;
            length=j-i+1;
            while(length-getMax(v)>k){
               v[s[i]-'A']--;
               i++; 
               length=j-i+1;
            }
            j++;
            maxlength=max(length,maxlength);
        }
        return maxlength;
    }
};