class Solution {
public:
    int mySqrt(int x) {
        int start = 0;
        int end = x;
        while(start<=end){
            long long mid = start + (end - start)/2;
            if(mid * mid > x) end = mid - 1;
            else if (mid * mid <x) start = mid + 1;
            else return mid;
        }
        return end;
    }
};