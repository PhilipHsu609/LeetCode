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
    int pairSum(ListNode* head) {
        vector<int> vals;

        ListNode *fast = head, *slow = head;
        while(fast != nullptr && fast->next != nullptr) {
            vals.push_back(slow->val);
            slow = slow->next;
            fast = fast->next->next;
        }

        int ret = 0;
        int i = vals.size() - 1;
        while(slow != nullptr) {
            ret = max(ret, slow->val + vals[i--]);
            slow = slow->next;
        }

        return ret;
    }
};