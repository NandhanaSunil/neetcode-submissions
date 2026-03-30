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
        if (head == nullptr) return head;
        
        unordered_map<Node*, Node*> addr_map;
        addr_map[nullptr] = nullptr;

        Node* start = head;
        Node* headnode = new Node(head->val);
        addr_map[head] = headnode;
        
        Node* startnode = headnode;
        start = start->next;
        while (start!=nullptr){
            Node* newnode = new Node(start->val);
            startnode -> next = newnode;
            startnode = newnode;
            addr_map[start] = newnode;
            start = start->next;
        }

        Node* cur = head;
        Node* curnode = headnode;
        while(cur != nullptr){
            curnode->random = addr_map[cur->random];
            cur = cur ->next;
            curnode = curnode->next;
        }
        return headnode;

    }
};
