class Solution {
    bool isSafe(vector<vector<char>>& board, int row, int col, char ch){
        for(int i = 0; i<9; i++){
            if(i==row) continue;
            if(board[i][col]==ch) return false;
        }

        for(int i = 0; i<9; i++){
            if(i==col) continue;
            if(board[row][i]==ch) return false;
        }

        int newRow = row - (row)%3;
        int newCol = col - (col)%3;

        for(int i = newRow; i<newRow+3; i++){
            for(int j = newCol; j<newCol+3; j++){
                if(i == row && j == col) continue;
                if(board[i][j]==ch) return false;
            }   
        }

        return true;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i<9; i++){
            for(int j = 0; j<9; j++){
                if(board[i][j]!='.' && !isSafe(board, i, j, board[i][j]))
                    return false;
            }
        }
        return true;
    }
};