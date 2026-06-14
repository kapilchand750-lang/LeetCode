class Solution {

    bool solve(vector<vector<char>>& board, string& word, int row, int col, int idx){
        if(idx==word.size())
            return true;
        
        int dir[][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        int n = board.size();
        int m = board[0].size();

        for(int i = 0; i<4; i++){
            int nr = row + dir[i][0];
            int nc = col + dir[i][1];

            if(nr>=0 && nr<n && nc>=0 && nc<m && board[nr][nc] == word[idx]){
                char ch = board[nr][nc];
                board[nr][nc] = '.';

                if(solve(board, word, nr, nc, idx + 1))
                    return true;
                
                board[nr][nc] = ch;
            }
        }

        return false;
    }


public:
    bool exist(vector<vector<char>>& board, string word) {

        if(word.empty()) return true;
        
        int n = board.size();
        int m = board[0].size();

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(board[i][j] == word[0]){
                    char ch = board[i][j];
                    board[i][j] = '.';

                    if(solve(board, word, i, j, 1))
                        return true;
                
                    board[i][j] = ch;
                }
            }
        }
        return false;
    }
};