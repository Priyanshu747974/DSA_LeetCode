class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        unordered_set<string> stt;
        for(int i =0;i<bannedWords.size();i++){
            stt.insert(bannedWords[i]);
        }
        int cnt=0;
        for(int i =0;i<message.size();i++){
            if(stt.count(message[i])){
                cnt++;
            }
        }
        if(cnt>=2)return true;
        return false;
    }
};