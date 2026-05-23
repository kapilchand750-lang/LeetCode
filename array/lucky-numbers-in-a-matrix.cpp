class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<int>lucky;

        for(int i = 0; i<n; i++){
            int colIndex = 0;
            int rowMin = matrix[i][0];

            for(int j = 0; j<m; j++){
                if(matrix[i][j]<rowMin){
                    rowMin = matrix[i][j];
                    colIndex= j;
                }
            }

            int k = 0;
            while(k<n){
                if(matrix[k][colIndex]>rowMin) break;
                k++;
            }

            if(k==n)
                lucky.push_back(rowMin);
        }
        return lucky;
    }
};