class Solution {
public:
    bool isPerfectSquare(int num) {
        int start = 0;
        int end = num;
        while(start<=end){
            long long mid = start + (end - start)/2;
            if(mid * mid > num) end = mid-1;
            else if(mid * mid < num) start = mid + 1;
            else return true;
        }
        return false;
    }
};