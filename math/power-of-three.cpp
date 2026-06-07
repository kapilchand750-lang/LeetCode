#include<bits/stdc++.h>
class Solution {
public:
    bool isPowerOfThree(int n) {
        int maxPow = 1162261467; //3^19
        return (n>0 && (maxPow%n==0));
    }
};