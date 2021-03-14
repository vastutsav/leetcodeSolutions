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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *ptr1, *ptr2, *ptr3;
        ptr1 = ptr2 = ptr3 = head;
        for (int i = 0; i < k-1; ++i){
            ptr1 = ptr1->next;
        }
        ptr3 = ptr1;
        ptr1 = ptr1->next;
        for (;ptr1!=NULL;ptr1=ptr1->next){
            ptr2=ptr2->next;
        }
        cout << ptr2->val << " " << ptr3->val << endl;
        swap(ptr3->val, ptr2->val);
        
        return head;
    }
};