class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        int i;
        int instabilityScore;
        for(i= 0; i<=n; i++){
            int largest = *max_element(nums.begin(), nums.begin()+i);
            // return largest;
            int smallest = *min_element(nums.begin()+i, nums.end());
            // return smallest;
            instabilityScore = largest - smallest;

            if(instabilityScore <= k)
                return i;
        }

        return -1;
    }
};