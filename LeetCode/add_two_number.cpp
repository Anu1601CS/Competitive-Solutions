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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode * p = l1, *q = l2;
        
        int sum = 0, carry = 0;
        ListNode* result = NULL, *res = new ListNode(0);
        
        result = res;
        
        while(p != NULL || q != NULL) 
        {
            int x = p != NULL ? p->val : 0;
            int y = q != NULL ? q->val : 0;
            
            sum = x + y + carry;
            
            carry =  sum / 10;
            
            result->next =  new ListNode(sum % 10);
            
            result = result->next;
            
            
            if(p != NULL)
                p = p->next;
            
            if(q != NULL)
                q = q->next;
        }
        
        if(carry) 
        {
            result->next = new ListNode(carry);
        }
        
        return res->next;
        
    }
};