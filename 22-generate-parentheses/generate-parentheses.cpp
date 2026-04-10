class Solution {
public:
    vector<string> vec;
    void f(string curr,int open, int close, int n){
        if(curr.size()==2*n){
            vec.push_back(curr);
            return;
        }
        if(open<n){
            f(curr+"(",open+1,close,n);
        }
        if(close<open){
            f(curr+")",open,close+1,n);
        }
    }
    vector<string> generateParenthesis(int n) {
        f("",0,0,n);
        return vec;
    }
};