class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>val;
        for(int i = 0; i<numRows; i++){
            vector<int>row(i+1, 1);
            for(int j = 1; j<i; j++){
                row[j] = val[i-1][j-1]+val[i-1][j];
            }
            val.push_back(row);
        }
        return val;
    }
};