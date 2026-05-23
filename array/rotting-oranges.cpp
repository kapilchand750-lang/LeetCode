class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>>q;
        int fresh = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j]==2)
                    q.push({i, j});
                if(grid[i][j]==1)
                    fresh++;
            }
        }
        int time = 0;
        int arr[][2] = {{-1,0}, {0,1}, {1,0}, {0,-1}};
        while(!q.empty() && fresh>0){
            int size = q.size();
            time++;
            while(size--){
                auto i = q.front();
                q.pop();
                int r = i.first;
                int c = i.second;
                for(int i = 0; i<4; i++){
                    int nr = r + arr[i][0];
                    int nc = c + arr[i][1];
                    if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1){
                        grid[nr][nc] = 2;
                        q.push({nr,nc});
                        fresh--;
                    }
                }
            }
        }
        if(fresh == 0) return time;
        return -1;
    }
};