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
    void reorderList(ListNode* head) {
        ListNode *p = head;
        
        stack<ListNode *> myStack; 
        
        int size = 0;
        
        while(p != NULL)
        {
            ++size;
            myStack.push(p);
            p = p->next;
        }
        
        p = head;
        
        while(myStack.size() > ceil((double) size /2) )
        {
            ListNode *temp = myStack.top();
            myStack.pop();
            
            temp->next = NULL;
            
            ListNode *next = p->next; 
            p->next = temp;
            temp->next = next;
            
            p = next;
            
        }
        
        if(p != NULL)
            p->next = NULL;
    }
};