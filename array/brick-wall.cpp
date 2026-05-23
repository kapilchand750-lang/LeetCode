class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map <long long, int> gaps;
        for(int i=0; i<wall.size(); i++){
            long long pos = 0;
            for(int j=0; j<wall[i].size()-1; j++){
                pos += wall[i][j];
                gaps[pos]++;
            }
        }
        int maxGaps = 0;
        for(auto it : gaps) {
            if(maxGaps<it.second) maxGaps = it.second;
        }
        return wall.size() - maxGaps;
    }
};