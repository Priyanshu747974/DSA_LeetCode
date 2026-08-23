class Solution {
public:
    string defangIPaddr(string address) {
        vector<char> ans;
        for(int i =0;i<address.size();i++){
            if(address[i]!='.'){
                ans.push_back(address[i]);
            }
            if(address[i]=='.'){
                ans.push_back('[');
                ans.push_back('.');
                ans.push_back(']');
            }
        }
        string result(ans.begin(),ans.end());
        return result;
    }
};