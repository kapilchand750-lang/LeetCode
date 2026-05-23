class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int rows = grid.size();
        int columns = grid[0].size();
        int landcells = 0 ;
        int sharedsides = 0;
        for(int i =0; i<rows; i++){
            for(int j = 0; j<columns; j++ ){
                if(grid[i][j] == 1){
                    landcells++;
                    if( i>0 && grid[i-1][j] == 1) sharedsides++;
                    if( j>0 && grid[i][j-1] == 1) sharedsides++;
                }
            }
        }
        int perimeter = 0;
        perimeter = 4*landcells - 2*sharedsides;
        return perimeter;
    }
};