class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // row - iteration
        for (int i = 0; i<9; i++){
            vector<char> row = board[i];
            unordered_map<char, int> dup;
            for (char p : row){
                if(dup.count(p) && p != '.') {return false;}
                dup[p]++;
            }
        }

        // column iteration
        for(int i=0; i<9; i++){
            unordered_map<char, int> dup;
            for(int j=0; j<9; j++){
                if(dup.count(board[j][i]) && board[j][i]!='.') {return false;}
                dup[board[j][i]]++;
            }
        }

        // square iteration
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                //inside the box
                unordered_map<char, int> dup;
                for(int k=0; k<3; k++){
                    for(int l=0; l<3; l++){
                        if(dup.count(board[i*3+k][j*3+l]) && board[i*3+k][j*3+l]!='.') {return false;}
                        dup[board[i*3+k][j*3+l]]++;
                    }
                }
            }
        }

        return true;
    }
};
