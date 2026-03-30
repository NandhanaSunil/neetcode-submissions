class Solution {
public:
    int rows;
    int cols;
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int bfs(vector<vector<int>>& grid, int i, int j){
        vector<vector<int>> visit(rows, vector<int>(cols, false));
        queue<vector<int>> q;
        q.push({i, j});
        int steps = 0;
        visit[i][j] = true;
        while(!q.empty()){
            int size = q.size();
            for(int k=0; k<size; k++){
                vector<int> cur = q.front();
                q.pop();
                if(grid[cur[0]][cur[1]] == 2) return steps;
                for(auto& v : dirs){
                    int x = v[0] + cur[0];
                    int y = v[1] + cur[1];
                    if(x>=0 && y>=0 && x<rows && y<cols && grid[x][y] != 0 && !visit[x][y]){
                        q.push({x, y});
                        visit[x][y] = true;
                    }
                }
        
            }
            steps++;
        }
        return INT_MAX;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        vector<vector<int>> temp(rows, vector<int>(cols, INT_MAX));
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(grid[i][j] == 1){
                    temp[i][j] = min(temp[i][j], bfs(grid, i, j));
                    // cout << temp[i][j] << " ";
                }
            }
        }
        int minval = 0;
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(grid[i][j] == 1){
                    minval = max(temp[i][j], minval);
                }
            }
        }

        return minval==INT_MAX ? -1 : minval;
    }
};
