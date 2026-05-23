class Solution {
public:
    int times = 0;

    bool isSafe(int n, vector<vector<int>>&board, int row, int col){

        for(int i = row-1; i>=0; i--)
            if(board[i][col] == 1) return false;

        for(int i = row-1, j = col-1; i>=0 && j>=0; i--, j--)
            if(board[i][j] == 1) return false;
        
        for(int i = row-1, j = col+1; i>=0 && j<n; i--, j++)
            if(board[i][j] == 1) return false;

        return true;
    }

    void solve(int n, vector<vector<int>>&board, int row){
        if(row==n){
            times++;
            return;
        }

        for(int col = 0; col<n; col++){
            if(isSafe(n, board, row, col)){

                board[row][col] = 1;

                solve(n, board, row+1);

                board[row][col] = 0;
            }
        }
    }

    int totalNQueens(int n) {

        vector<vector<int>>board(n, vector<int>(n, 0));

        times = 0;

        solve(n, board, 0);

        return times;
    }
};