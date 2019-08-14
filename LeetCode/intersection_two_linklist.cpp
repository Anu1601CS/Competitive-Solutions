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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
     
        unordered_set<ListNode * > visited;
        
        ListNode *p =headA;
        
        while(p != NULL)
        {
            visited.insert(p);
            p = p->next;
        }
        
        ListNode *q = headB;
        
        while(q != NULL)
        {
            if(visited.find(q) != visited.end())
            {
                return q;
            }
            
            q = q->next;
        }
        
        return NULL;
        
    }
};