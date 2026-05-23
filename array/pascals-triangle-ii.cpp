class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result;
        long long num = 1;
        for(int i=0; i<=rowIndex; i++){
            result.push_back(num);
            num = num * (rowIndex - i)/(i + 1);
        }
        return result;
    }
};