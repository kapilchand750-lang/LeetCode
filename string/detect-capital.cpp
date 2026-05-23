class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size();
        int cnt = 0;
        for(int i = 0; i<n; i++){
            char ch = word[i];
            if(isupper(ch))
                cnt++;
        }
        return (cnt==0 || cnt == n || cnt == 1 && isupper(word[0]));
    }
};