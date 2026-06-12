class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==1) return strs[0];
        int n = 201;
        string small;
        for(int i = 0; i<strs.size(); i++){
            int m = strs[i].size();
            if(m<n) {
                small = strs[i];
                n = m;
            }
        }
        for(int i = 0; i<strs.size(); i++){
            string s1 = strs[i];
            int temp = 0;
            for(int k = 0; k<n; k++){
                if(s1[k]==small[k])
                    temp++;
                else break;
            }
            n = temp;
        }

        string res = small.substr(0, n);
        return res;
    }
};