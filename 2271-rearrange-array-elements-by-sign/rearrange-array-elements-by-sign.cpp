class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>pos;
        vector<int>neg;
        for(auto it : nums){
            if(it>=0){
                pos.push_back(it);
            }
            else{
                neg.push_back(it);
            }
        }
        int i =0;
        int j =0;
        vector<int> ans;
        while(i<pos.size()){
            ans.push_back(pos[i]);
            ans.push_back(neg[i]);
            i++;
            j++;
        }
        return ans;
    }
};