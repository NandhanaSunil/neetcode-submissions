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
                if(grid[cur[0]][cur[1]] == 0) return steps;
                for(auto& v : dirs){
                    int x = v[0] + cur[0];
                    int y = v[1] + cur[1];
                    if(x>=0 && y>=0 && x<rows && y<cols && grid[x][y] != -1 && !visit[x][y]){
                        q.push({x, y});
                        visit[x][y] = true;
                    }
                }
        
            }
            steps++;
        }
        return INT_MAX;
    }

    void islandsAndTreasure(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(grid[i][j] == INT_MAX){
                    grid[i][j] = min(grid[i][j], bfs(grid, i, j));
                }
            }
        }
        return;
    }
};
