class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size(), n = image[0].size();
        int oc = image[sr][sc];

        if(oc == color) {
            return image;
        }

        queue<array<int, 2>> q;
        vector<int> dir{0, 1, 0, -1, 0};
        q.push({sr, sc});

        while(!q.empty()) {
            auto [y, x] = q.front();
            q.pop();

            image[y][x] = color;
            for(int d = 0; d < 4; ++d) {
                int ny = y + dir[d];
                int nx = x + dir[d + 1];

                if(ny < 0 || nx < 0 || ny == m || nx == n || oc != image[ny][nx]) {
                    continue;
                }

                q.push({ny, nx});
            }
        }

        return image;
    }
};