class Solution {
public:
    vector<vector<string>>res;
    bool isSafe(int r, int c, unordered_set<int>col, 
        unordered_set<int>pos, unordered_set<int>neg){
            if(col.find(c)!=col.end() || pos.find(r+c)!=pos.end() || neg.find(r-c) != neg.end()){
                return false;
            }
            return true;
    }

    void dfs(vector<string> board, int r, int n,
        unordered_set<int>col, unordered_set<int>pos,
        unordered_set<int>neg){
        if(r==n){
            res.push_back(board);
            return;
        }
        for(int c=0; c<n; c++){
            if(isSafe(r, c, col, pos, neg)){
                board[r][c] = 'Q';
                col.insert(c);
                pos.insert(r+c);
                neg.insert(r-c);
                dfs(board, r+1, n, col, pos, neg);
                board[r][c] = '.';
                col.erase(c);
                pos.erase(r+c);
                neg.erase(r-c);
            }
            else continue;
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        // string row('.', n);
        unordered_set<int> col;
        unordered_set<int>pos;
        unordered_set<int>neg;
        vector<string> board(n, string (n, '.'));
        dfs(board, 0, n, col, pos, neg);
        return res;
    }
};
