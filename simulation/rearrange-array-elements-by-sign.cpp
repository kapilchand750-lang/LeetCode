class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector <int> pos, neg;
        for( auto i : nums ){
            if(i>=0) pos.push_back(i);
            else neg.push_back(i);
        }
        nums.clear();
        int i= 0 ,  j=0;
        while(i<pos.size() && j<neg.size()){
            nums.push_back(pos[i++]);
            nums.push_back(neg[j++]);
        }
        while(i<pos.size()) nums.push_back(pos[i++]);
        while(j<neg.size()) nums.push_back(neg[j++]);
        return nums;
    }
};