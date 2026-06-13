class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        return words | views::transform([&weights](const string &w) {
            int sum = ranges::fold_left(w, 0, [&weights](int x, char w) {
                return (x + weights[w - 'a']) % 26;
            });
            return static_cast<char>('z' - sum);
        }) | ranges::to<string>();
    }
};