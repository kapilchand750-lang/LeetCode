class Solution {
public:
    int minBitFlips(int start, int goal) {
        int res = start ^ goal;
        int cnt = 0;
        while(res){
            cnt++;
            res = res&(res-1);
        }
        return cnt;
    }
};