class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(),wordList.end());
        queue<pair<string,int>> q;
        unordered_set<string> vis;
        q.push({beginWord,1});
        vis.insert(beginWord);

        while(!q.empty()){
            string word=q.front().first;
            int step=q.front().second;
            q.pop();
            if(word==endWord){
                return step;
            }
            for(int i=0;i<word.size();i++){
                char original=word[i];
                for(char j='a';j<='z';j++){
                    word[i]=j;
                    if(st.count(word) && !vis.count(word)){
                        vis.insert(word);
                        q.push({word,step+1});
                    }
                }
                word[i]=original;
            }
        }
        return 0;
    }
};