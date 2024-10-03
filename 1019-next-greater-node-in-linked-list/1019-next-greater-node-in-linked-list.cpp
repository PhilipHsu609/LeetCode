/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ret;
        stack<array<int, 2>> s; // {val, idx}

        int i = 0;
        while(head != nullptr) {
            ret.push_back(0);
            while(!s.empty() && s.top()[0] < head->val) {
                auto [val, idx] = s.top(); s.pop();
                ret[idx] = head->val;
            }
            s.push({head->val, i});
            i++;
            head = head->next;
        }

        return ret;
    }
};