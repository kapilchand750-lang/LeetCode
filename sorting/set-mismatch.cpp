class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> mp;
        int duplicate = 0;

        for(int x : nums) {
            mp[x]++;

            if(mp[x] == 2)
                duplicate = x;
        }

        int lost = 0;

        for(int i = 1; i <= n; i++) {
            if(mp.find(i) == mp.end()) {
                lost = i;
                break;
            }
        }

        return {duplicate, lost};
    }
};