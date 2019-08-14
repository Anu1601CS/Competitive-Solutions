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
    ListNode* swapPairs(ListNode* head) {
        
        ListNode *prev, *curr;
        
        if(head == NULL || head->next == NULL)
            return head;
        
        curr = head->next->next;
        prev = head;
        head = head->next;
        head->next = prev;
        
        while(curr != NULL && curr->next != NULL )
        {   
            prev->next = curr->next;
            prev = curr; 
            ListNode *temp = curr->next->next; 
            curr->next->next = curr; 
            curr = temp; 
        }
        
        prev->next = curr;
        
        return head;
        
    }
};