#include<bits/stdc++.h>
class Solution {
public:

    vector<vector<string>>ans;

    bool isSafe(int n, vector<string>&board, int row, int col){

        for(int i = row-1; i>=0; i--)
            {if(board[i][col]=='Q') return false;}

        for(int i = row-1, j = col-1; i>=0 && j>=0; i--, j--)
            {if(board[i][j]=='Q') return false;}

        for(int i = row-1, j = col+1; i>=0 && j<n; i--, j++)
           { if(board[i][j]=='Q')  return false;}
        
        return true;

    }
    void solve(int n, vector<string>&board , int row){
        if(row==n){
            ans.push_back(board);
            return;
        }

        for(int col = 0; col<n; col++){
            if(isSafe(n, board, row, col)){
                board[row][col] = 'Q';

                solve(n, board, row+1);

                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string>board(n, string(n, '.'));

        solve(n, board, 0);

        return ans;

    }
};