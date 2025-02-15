class Solution {
public:
    int punishmentNumber(int n) {
        int ret = 0;
        for(int i = 1; i <= n; i++) {
            int sq = i * i;

            if(canPartition(to_string(sq), i)) {
                ret += sq;
            }
        }
        return ret;
    }

    bool canPartition(const string &s, int target) {
        if(s.empty() && target == 0) {
            return true;
        }

        if(target < 0) {
            return false;
        }

        for(int i = 0; i < s.size(); i++) {
            string l = s.substr(0, i + 1);
            string r = s.substr(i + 1);

            if(canPartition(r, target - stoi(l))) {
                return true;
            }
        }
        
        return false;
    }
};