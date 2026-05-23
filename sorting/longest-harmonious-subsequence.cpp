class Solution {
public:
    int findLHS(vector<int>& nums) {
        int maxlhs = 0;
        unordered_map <int, int> freq;
        for(auto i : nums) freq[i]++;
        for(auto j : nums){
             if(freq.count(j+1)) maxlhs = max(maxlhs, freq[j]+freq[j+1]);
      }
      return maxlhs;
    }
};