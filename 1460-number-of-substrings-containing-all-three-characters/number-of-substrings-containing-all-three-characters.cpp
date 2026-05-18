class Solution {
public:
    int numberOfSubstrings(string s) {
        int acnt = 0;
        int bcnt = 0;
        int ccnt = 0;
        int cnt = 0;
        int i = 0;
        int j = 0;
        while (j < s.size()) {
            if (s[j] == 'a') {
                acnt++;
            }
            if (s[j] == 'b') {
                bcnt++;
            }

            if (s[j] == 'c') {
                ccnt++;
            }
            while(acnt>0 && bcnt>0 && ccnt>0){
                cnt += s.size() - j;
                if(s[i]=='a'){
                     acnt--;
                }
                if(s[i]=='b'){
                     bcnt--;
                }
                if(s[i]=='c'){
                     ccnt--;
                }
                i++;   
            }
            j++;
        }
        return cnt;
    }
};