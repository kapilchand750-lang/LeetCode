class Solution {
private:
    void dfs(int n, int m, int r, int c, vector<vector<char>>& grid, int dir[][2]){
        grid[r][c] = '0';
        for(int i = 0; i<4; i++){
            int nr = r + dir[i][0];
            int nc = c + dir[i][1];
            if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]=='1')
                dfs(n, m, nr, nc, grid, dir);
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int dir[][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        int com = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j]=='1'){
                    com++;
                    dfs(n, m, i, j, grid, dir);
                }
            }
        }
        return com;
    }
};