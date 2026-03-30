class Solution {
public:
    int numislands;

    void bfs(vector<vector<char>>& grid, int i, int j){
        queue<pair<int, int>> vertpair;
        vertpair.push({i,j});
        while(!vertpair.empty()){
            auto &p = vertpair.front();
            vertpair.pop();
            int x = p.first;
            int y = p.second;

            if(x>0 && grid[x-1][y] == '1'){
                vertpair.push({x-1, y});
            }
            if(y>0 && grid[x][y-1] == '1') vertpair.push({x, y-1});
            if(x<grid.size()-1 && grid[x+1][y] == '1') vertpair.push({x+1, y});
            if(y<grid[0].size()-1 && grid[x][y+1] == '1') vertpair.push({x, y+1});
            grid[x][y] = '#';
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        
        numislands = 0;
        for(int i=0; i<grid.size(); i++){
            for (int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    bfs(grid, i, j);
                    numislands++;
                }
            }
        }
        return numislands;
    }
};
