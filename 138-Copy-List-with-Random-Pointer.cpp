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
        unordered_map<Node*, Node*>copies;

        Node* cur = head;
        while(cur){
            Node* copy = new Node(cur->val);
            copies[cur] = copy;
            cur = cur->next;
        }
        
        cur = head;
        while(cur){
            Node* copy = copies[cur];
            copy->next = copies[cur->next];
            copy->random = copies[cur->random];
            cur = cur->next;
        }
    
        return copies[head];
    }
};
