class Solution {
public:

    bool checkrow(vector<char> row){
        unordered_set<char> rowset;
        for(char c : row){
            if(c!='.'){
                if (rowset.find(c)!=rowset.end()) return false;
                rowset.insert(c);
            }
        }
        return true;
    }

    bool checkcol(int ind, vector<vector<char>>& board){
        unordered_set<char> colset;
        for(int i=0; i<9; i++){
            if(board[i][ind] != '.'){
                if (colset.find(board[i][ind]) != colset.end()) return false;
                colset.insert(board[i][ind]);
            }
        }
        return true;
    }

    bool checkbox(int ind, vector<vector<char>>& board){
        unordered_set<char> boxset;
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(board[ind+i][j] != '.'){
                    if(boxset.find(board[ind+i][j]) != boxset.end()) return false;
                    boxset.insert(board[ind+i][j]);
                }
            }
        }

        unordered_set<char> boxset2;
        for(int i=0; i<3; i++){
            for(int j=3; j<6; j++){
                if(board[ind+i][j] != '.'){
                    if(boxset2.find(board[ind+i][j]) != boxset2.end()) return false;
                    boxset2.insert(board[ind+i][j]);
                }
            }
        }

        unordered_set<char> boxset3;
        for(int i=0; i<3; i++){
            for(int j=6; j<9; j++){
                if(board[ind+i][j] != '.'){
                    if(boxset3.find(board[ind+i][j]) != boxset3.end()) return false;
                    boxset3.insert(board[ind+i][j]);
                }
            }
        }

        return true;
    }


    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0; i<9; i++){
            if(!checkrow(board[i])) return false;
            if(!checkcol(i, board)) return false;
        }
        for(int i=0; i<9; i+=3){
            if(!checkbox(i, board)) return false;
        }

        return true;

    }
};
