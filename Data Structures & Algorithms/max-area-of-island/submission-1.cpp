class Solution {
public:
    int bfs(vector<vector<int>>& grid, int i, int j){
        int a = 0;
        queue<pair<int, int>> vertpair;
        vertpair.push({i,j});
        grid[i][j] = 2;
        while(!vertpair.empty()){
            auto &p = vertpair.front();
            a++;
            vertpair.pop();
            int x = p.first;
            int y = p.second;
            cout << x << " " << y << endl;

            if(x>0 && grid[x-1][y] == 1){
                vertpair.push({x-1, y});
                grid[x-1][y] = 2;
            }
            if(y>0 && grid[x][y-1] == 1){
                vertpair.push({x, y-1});
                grid[x][y-1] = 2;
                }
            if(x<grid.size()-1 && grid[x+1][y] == 1){
                vertpair.push({x+1, y});
                grid[x+1][y] = 2;
                }
            if(y<grid[0].size()-1 && grid[x][y+1] == 1){
                vertpair.push({x, y+1});
                grid[x][y+1] = 2;
                }
        }
        return a;
    }

    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int a = 0;
        for(int i=0; i<grid.size(); i++){
            for (int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 1){
                    a = max(a,bfs(grid, i, j));
                }
            }
        }
        return a;
    }
};
