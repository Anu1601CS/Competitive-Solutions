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
    ListNode *detectCycle(ListNode *head) {
        
        int count = 0;
        unordered_map<ListNode *, int> myMap;
        
        ListNode *p = head;
        
        while( p != NULL)
        {
            if(myMap.find(p) != myMap.end())
            {
                return p;
            }
            
            myMap.insert(make_pair(p, count));
            
            ++count;
            p = p->next;
        }
        
        return NULL;
        
    }
};