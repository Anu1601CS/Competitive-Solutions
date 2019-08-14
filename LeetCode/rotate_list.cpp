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
    ListNode* rotateRight(ListNode* head, int k) {
        
        int index = k;
        
        if(head == NULL || head->next == NULL)
            return head;
        
        ListNode *q = head;
        int count = 0;
        
        while( q != NULL )
        {
            ++count;
            q = q->next;
        }
        
        int run = k % count;
        
        while(run--)
        {
            ListNode *p = head, *prev= NULL;
               
            while( p != NULL && p->next != NULL)
            {
                prev = p;
                p = p->next;
            }
            
            p->next = head;
            head = p;
            prev->next = NULL;
            p = head;
        
        }
        
        return head;
    
    }
};