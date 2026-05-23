class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        unordered_set<int>set;
        for(auto a : nums)
            set.insert(a);
        int largest = 1;
        for(auto a : set){
            if(set.find(a-1) == set.end()){
                int cnt = 1;
                int next = a;
                while(set.find(next + 1)!=set.end()){
                    cnt++;
                    next++;
                }
                largest = max(largest, cnt);
            }
        }
        return largest;
    }
};