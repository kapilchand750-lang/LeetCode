class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();

        vector<int>sortedCopy = nums;
        sort(sortedCopy.begin(), sortedCopy.end());

        unordered_map<int, int>firstIdxMap;
        for(int i = 0; i<n; i++){
            if(firstIdxMap.find(sortedCopy[i])==firstIdxMap.end())
                firstIdxMap[sortedCopy[i]] = i;
        }

        vector<int>cnt(n, 0);

        for(int i = 0; i<n; i++)
            cnt[i] = firstIdxMap[nums[i]];

        return cnt;
    }
};