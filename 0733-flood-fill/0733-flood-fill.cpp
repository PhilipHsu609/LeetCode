class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oc = image[sr][sc];

        if(oc == color) {
            return image;
        }

        int m = image.size(), n = image[0].size();
        vector<int> dir{0, 1, 0, -1, 0};
        queue<array<int, 2>> q;
        q.push({sr, sc});

        while(!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            if(r < 0 || c < 0 || r == m || c == n || image[r][c] != oc) {
                continue;
            }

            image[r][c] = color;
            
            for(int d = 0; d < 4; ++d) {
                int nr = r + dir[d];
                int nc = c + dir[d + 1];
                q.push({nr, nc});
            }
        }

        return image;
    }
};