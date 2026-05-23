class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int dir[][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        queue<pair<int, int>>q;
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(mat[i][j]==0)
                q.push({i, j});
            }
        }

        vector<vector<int>>copy(n, vector<int>(m, 0));

        int time = 0;

        while(!q.empty()){
            int size = q.size();
            time++;
            while(size--){
                auto it = q.front();
                q.pop();
                int r = it.first;
                int c = it.second;
                for(int i = 0; i<4; i++){
                    int nr = r + dir[i][0];
                    int nc = c + dir[i][1];
                    if(nr>=0 && nr<n && nc>=0 && nc<m && mat[nr][nc]==1 && copy[nr][nc]==0)
                        {copy[nr][nc] = time;
                        q.push({nr, nc});}
                }
            }
        }
        return copy;
    }
};