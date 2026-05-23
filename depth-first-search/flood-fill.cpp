class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int originalColor = image[sr][sc];
        if(originalColor ==  color) return image;
        int dir[][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        int n = image.size();
        int m = image[0].size();
        image[sr][sc] = color;
        queue<pair<int, int>>q;
        q.push({sr, sc});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int r = it.first;
            int c = it.second;
            for(int i = 0; i<4; i++){
                int nr = r + dir[i][0];
                int nc = c + dir[i][1];
                if(nr>=0 && nr<n && nc>=0 && nc<m && image[nr][nc]==originalColor){
                    image[nr][nc] = color;
                    q.push({nr, nc});
                }
            }
        }
        return image;
    }
};