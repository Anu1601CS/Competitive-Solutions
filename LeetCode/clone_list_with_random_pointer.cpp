/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        Node * p = head, *dummyclone;
        
        unordered_map<Node * , Node *> myMap;
        
        while(p != NULL)
        {
            dummyclone = new Node(p->val, NULL, NULL);
            
            myMap[p] = dummyclone;
            
            p = p->next;
        }
        
        p = head;
        
        Node *clone;
        
        while(p != NULL)
        {
            clone = myMap[p];
            clone->next = myMap[p->next];
            clone->random = myMap[p->random];
            p = p->next;
        }
        
        return myMap[head];
    }
};