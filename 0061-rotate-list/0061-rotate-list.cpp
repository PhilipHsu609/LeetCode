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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr) {
            return head;
        }
        
        ListNode **indir{&head};
        int cnt = 1;

        while((*indir)->next != nullptr) {
            indir = &(*indir)->next;
            ++cnt;
        }

        k %= cnt;

        (*indir)->next = head;

        indir = &head;
        for(int i = 0; i < cnt - k; ++i) {
            indir = &(*indir)->next;
        }

        head = *indir;
        *indir = nullptr;

        return head;
    }
};