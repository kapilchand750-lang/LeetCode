class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>spiral(n, vector<int>(n,0));
        int k = 1;
        int rb = 0, re = n-1;
        int cb = 0, ce=n-1;
        while(rb<=re && cb<=ce){
            for(int i = cb; i<=ce; i++) spiral[rb][i]=k++;
            rb++;
            for(int i = rb; i<=re; i++) spiral[i][ce]=k++;
            ce--;
            if(rb<=re){
                for(int i = ce; i>=cb; i--) spiral[re][i]=k++;
                re--;
            }
            if(cb<=ce){
                for(int i = re; i>=rb; i--) spiral[i][cb]=k++;
                cb++;
            }
        }
        return spiral;
    }
};