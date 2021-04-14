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
    ListNode* partition(ListNode* head, int x) {
        ListNode left(0), right(0);
        ListNode *l = &left, *r = &right;
        ListNode* itr = head;
        
        while (itr) {
            if (itr->val < x) {
                l->next = itr;
                l = l->next;
            }
            else {
                r->next = itr;
                r = r->next;
            }
            itr = itr->next;
        }
        r->next = NULL;
        l->next = right.next;
        return left.next;
        
    }
};