class Solution {
private:
    void dfs(int n, int m, int r, int c, vector<vector<char>>& board, vector<vector<int>>&vst, int dir[][2]){
        vst[r][c] = 1;
        for(int i = 0; i<4; i++){
            int nr = r + dir[i][0];
            int nc = c + dir[i][1];
            if(nr>=0 && nr<n && nc>=0 && nc<m && !vst[nr][nc] && board[nr][nc]=='O')
                dfs(n, m, nr, nc, board, vst, dir);
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>>vst(n, vector<int>(m, 0));

        int dir[][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        for(int i = 0; i<m; i++){
            if(!vst[0][i] && board[0][i]=='O')
                dfs(n, m, 0, i, board, vst, dir);
            if(!vst[n-1][i] && board[n-1][i]=='O')
                dfs(n, m, n-1, i, board, vst, dir);
        }

        for(int j = 0; j<n; j++){
            if(!vst[j][0] && board[j][0]=='O')
                dfs(n, m, j, 0, board, vst, dir);
            if(!vst[j][m-1] && board[j][m-1]=='O')
                dfs(n, m, j, m-1, board, vst, dir);
        }

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(!vst[i][j]&& board[i][j]=='O')
                    board[i][j] = 'X';
            }
        }
    }
};