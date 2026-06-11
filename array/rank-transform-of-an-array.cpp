class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int>copy = arr;
        sort(copy.begin(), copy.end());

        unordered_map<int, int>rank;
        int duplicate = 0;
        for(int i = 0; i<n; i++){
            if(rank.find(copy[i]) == rank.end())
                rank[copy[i]] = i + 1 - duplicate;
            else duplicate++;
        }
        vector<int>ans(n, 0);

        for(int i = 0; i<n; i++)
            ans[i] = rank[arr[i]];
        
        return ans;
    }
};