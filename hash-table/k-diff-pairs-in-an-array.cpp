class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(auto n : nums) freq[n]++;
        int cnt = 0;
        if(k==0){
            for(auto &p : freq)
                if(p.second>1) cnt++;
        }
        else {
            for(auto &p : freq){
                if(freq.find(p.first + k)!=freq.end()) cnt++;
            }
        }
        return cnt;
    }
};