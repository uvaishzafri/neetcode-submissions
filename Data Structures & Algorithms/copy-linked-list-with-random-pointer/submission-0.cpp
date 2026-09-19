/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
   public:
    Node* copyRandomList(Node* head) {
        if (!head) return NULL;
        unordered_map<Node*, Node*> m;
        for (Node* c = head; c; c = c->next) m[c] = new Node(c->val);
        for (Node* c = head; c; c = c->next) {
            m[c]->next = m[c->next];
            m[c]->random = m[c->random];
        }
        return m[head];
    }
};
