class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int dir[][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        queue<pair<int, int>>q;

        for(int i = 0; i<n; i++){
            if(grid[i][0]==1){
                q.push({i, 0});
                grid[i][0] = 0;
            }
            if(grid[i][m-1]==1){
                q.push({i, m-1});
                grid[i][m-1] = 0;
            }
        }

        for(int j = 0; j<m; j++){
            if(grid[0][j]==1){
                q.push({0, j});
                grid[0][j] = 0;
            }
            if(grid[n-1][j]==1){
                q.push({n-1, j});
                grid[n-1][j] = 0;
            }
        }

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int r = it.first;
            int c = it.second;
            for(int i = 0; i<4; i++){
                int nr = r + dir[i][0];
                int nc = c + dir[i][1];
                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1){
                    grid[nr][nc] = 0;
                    q.push({nr, nc});
                }
            }
        }
        int enclave = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m ;j++){
                if(grid[i][j]==1)
                    enclave = enclave + 1;
            }
        }

        return enclave;
    }
};