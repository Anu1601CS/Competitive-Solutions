/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        
        ListNode *p = head, *d = head;
        
        while(d && d->next != NULL)
        {
            d = d->next->next;
            p = p->next;
        }
        
        return p;
    }
};