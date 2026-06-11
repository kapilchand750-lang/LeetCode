class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int>copy = arr;
        sort(copy.begin(), copy.end());

        unordered_map<int, int>rank;
        int Rank = 1;
        for(auto num : copy){
            if(rank.find(num)==rank.end()){
                rank[num] = Rank;
                Rank++;
            }
        }
        
        for(int i = 0; i<n; i++)
            copy[i] = rank[arr[i]];
        
        return copy;
    }
};