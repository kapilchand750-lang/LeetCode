#include<bits/stdc++.h>
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0, candidate = 0;
        for( auto i : nums){
            if(count ==0){
                candidate = i;
            }
            count += (candidate==i)?1:-1;
        }
        return candidate;
    }
};