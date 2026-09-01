class Solution {
    bool isSafe(vector<vector<char>>& board, int row, int col, char c){
        for(int i = 0; i<9; i++){
            if(board[i][col]==c) return false;
            if(board[row][i]==c) return false;
        }

        int nr = row - (row)%3;
        int nc = col - (col)%3;

        for(int i = nr; i<nr+3; i++){
            for(int j = nc; j<nc+3; j++){
                if(board[i][j]==c) return false;
            }
        }
        return true;
    }

    bool solve(vector<vector<char>>& board, int idx, vector<pair<int, int>>&emptyCells){
        
        if(idx==emptyCells.size())
            return true;

        int row = emptyCells[idx].first;
        int col = emptyCells[idx].second;

        for(char c = '1'; c<='9'; c++){
            if(isSafe(board, row, col, c)){
                board[row][col] = c;
                if(solve(board, idx + 1, emptyCells))
                    return true;
                board[row][col] = '.';
            }
        }
        return false;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<pair<int, int>>emptyCells;
        for(int i = 0; i<9; i++){
            for(int j = 0; j<9; j++){
                if(board[i][j]=='.')
                    emptyCells.push_back({i, j});
            }
        }
        solve(board, 0, emptyCells);
    }
};