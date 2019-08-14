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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        int index = 0;
        int length = 0;
        
        ListNode *prev = NULL, *curr = head, *p = head;
        
        while(p!=NULL) {
            ++length;
            p = p->next;
        }
        
        int remove = length - n;
        
        if(remove == 0)
        {
            head = head->next;
            return head;
        }
        
        while(curr != NULL)
        {
            if(remove == index)
            {
                prev->next  = curr->next;
                break;
            }
            
            ++index;
                
            prev = curr;    
            curr = curr->next;
        }
            
    
        
        return head;
        
    }
};