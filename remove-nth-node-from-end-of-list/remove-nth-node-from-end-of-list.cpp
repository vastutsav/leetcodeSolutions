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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode *itr1, *itr2, *itr3;
        int i=0;
        
        ListNode *tmp = new ListNode();
        tmp->next = head;
        itr1 = itr2 = head;
        itr3 = tmp;
        
        while (i < n) {
            itr1 = itr1->next;
            ++i;
        }
        
        while (itr1!=NULL)
        {
            itr1 = itr1->next;
            itr2 = itr2->next;
            itr3 = itr3->next;
        }

        itr3->next = itr2->next;
        
        
        return tmp->next;
        
    }
};