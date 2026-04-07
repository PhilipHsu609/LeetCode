class Robot {
public:
    Robot(int width, int height) : width(width), height(height) {
        x = y = d = 0;
        dirs.reserve(4);
        dirs.push_back({1, 0});
        dirs.push_back({0, 1});
        dirs.push_back({-1, 0});
        dirs.push_back({0, -1});
    }
    
    void step(int num) {
        int mod = (2 * (width - 1) + 2 * (height - 1));

        if(num % mod == 0 && x == 0 && y == 0) {
            d = 3;
            return;
        }

        num = num % mod;
        while(num > 0) {
            int xx = x + num * dirs[d][0];
            int yy = y + num * dirs[d][1];

            if(d == 0 && xx >= width) {
                num -= width - 1 - x;
                xx = width - 1;
                d = 1;
            } else if(d == 2 && xx < 0) {
                num -= x;
                xx = 0;
                d = 3;
            } else if(d == 1 && yy >= height) {
                num -= height - 1 - y;
                yy = height - 1;
                d = 2;
            } else if(d == 3 && yy < 0) {
                num -= y;
                yy = 0;
                d = 0;
            } else {
                num = 0;
            }

            x = xx;
            y = yy;
        }
    }
    
    vector<int> getPos() {
        return {x, y};
    }
    
    string getDir() {
        if(d == 0) {
            return "East";
        }
        if(d == 1) {
            return "North";
        }
        if(d == 2) {
            return "West";
        }
        return "South";
    }

    int width = 0;
    int height = 0;

    int x = 0;
    int y = 0;

    int d = 0;
    vector<array<int, 2>> dirs;
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */