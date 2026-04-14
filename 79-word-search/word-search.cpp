class Solution {
public:
    bool function(int i,int j,int index,vector<vector<char>>& board,string& word){
       if(index ==word.size()){
        return true;
       }
       if(i<0 || j<0 ||i>=board.size() || j>=board[0].size() || board[i][j]!=word[index]){
        return false;
       }
       char temp=board[i][j];
       board[i][j]='#';
       bool found=function(i+1,j,index+1,board,word)||
                  function(i-1,j,index+1,board,word)||
                  function(i,j+1,index+1,board,word)||
                  function(i,j-1,index+1,board,word);
        board[i][j]=temp;

        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        
        int n= board.size();
        int m= board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(function(i,j,0,board,word)){
                    return true;
                }
            }
        }
        return false;
    }
};