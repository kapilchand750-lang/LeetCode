class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;

        vector<vector<int>>dir = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
        queue<pair<int, int>>q;
        q.push({0,0});
        grid[0][0] = 1;

        int pathlen = 1;

        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto it = q.front();
                q.pop();
                int r = it.first;
                int c = it.second;

                if(r==n-1 && c==n-1) return pathlen;

                for(int i = 0; i<8; i++){
                    int nr = r + dir[i][0];
                    int nc = c + dir[i][1];

                    if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==0){
                        grid[nr][nc] = 1;
                        q.push({nr, nc});
                    }
                }
            }
            pathlen++;
        }
        return -1;
    }
};