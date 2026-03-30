class Solution {
public:
    bool dfs(int i, int j, string f, string word, vector<vector<char>>&board){
        if(f.size() == word.size()) return false;
        f= f+board[i][j];
        if(f==word) return true;
        char temp = board[i][j];
        board[i][j] = '#';
        bool found = false;
        if(i+1 < board.size()) found = found || dfs(i+1, j, f, word, board);
        if(i-1 >= 0) found = found || dfs(i-1, j, f, word, board);
        if(j+1<board[0].size()) found = found || dfs(i, j+1, f, word, board);
        if(j-1 >=0) found = found || dfs(i, j-1, f, word, board);
        board[i][j] = temp;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j] == word[0]){
                    bool found = dfs(i, j, "", word, board);
                    if (found ) return true;
                }
            }
        }
        return false;
    }
};
