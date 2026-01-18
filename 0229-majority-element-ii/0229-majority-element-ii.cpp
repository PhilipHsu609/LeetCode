class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cand1 = 0, cand2 = 0, cnt1 = 0, cnt2 = 0;
        for(int n : nums) {
            if(n == cand1)
                cnt1++;
            else if(n == cand2)
                cnt2++;
            else if(!cnt1)
                cand1 = n, cnt1 = 1;
            else if(!cnt2)
                cand2 = n, cnt2 = 1;
            else
                cnt1--, cnt2--;
        }

        cout << cand1 << ' ' << cand2 << endl;

        int maj = nums.size() / 3;
        vector<int> ans;
        cnt1 = 0, cnt2 = 0;
        for(int n : nums) {
            if(n == cand1)
                cnt1++;
            else if(n == cand2)
                cnt2++;
        }

        if(cnt1 > maj)
            ans.push_back(cand1);
        if(cnt2 > maj)
            ans.push_back(cand2);

        return ans;
    }
};