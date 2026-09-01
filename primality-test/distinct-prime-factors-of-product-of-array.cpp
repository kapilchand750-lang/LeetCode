class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        int max = *max_element(nums.begin(), nums.end());

        vector<int>spfSieve(max+1);

        for(int i = 0; i<=max; i++) spfSieve[i] = i;

        for(int i = 2; i*i<=max; i++){
            if(spfSieve[i]==i){
                for(int j = i*i; j<=max; j = j+i){
                    if(spfSieve[j]==j) 
                        spfSieve[j] = i;
                }
            }
        }

        unordered_set<int>uniquePrimeFactors;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            int a = nums[i];
            while(a!=1){
                uniquePrimeFactors.insert(spfSieve[a]);
                a = a/spfSieve[a];
            }
        }
        return uniquePrimeFactors.size();
    }
};