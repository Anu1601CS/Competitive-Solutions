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
    ListNode* deleteDuplicates(ListNode* head) {
    
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* cur = dummy;
        
        int duplicate;
        
        while (cur->next && cur->next->next) {
           
            if (cur->next->val == cur->next->next->val) {
                duplicate = cur->next->val;
        
                while (cur->next && cur->next->val == duplicate) {
                    cur->next = cur->next->next;
                }
            }
            else {
                cur = cur->next;
            }
        }
        return dummy->next;

        
    }
};