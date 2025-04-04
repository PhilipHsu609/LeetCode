class Solution {
public:
    bool isCircularSentence(string sentence) {
        if(sentence.front() != sentence.back()) {
            return false;
        }

        int n = sentence.length();
        for(int i = 0; i < n; i++) {
            if(sentence[i] == ' ') {
                if(sentence[i - 1] != sentence[i + 1]) {
                    return false;
                }
            }
        }

        return true;
    }
};