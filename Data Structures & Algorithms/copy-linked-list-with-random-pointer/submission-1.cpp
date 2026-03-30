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
        unordered_map<Node*, Node*>mp;
        Node* curr = head;
        while(curr){
            Node* tmp = new Node(curr->val);
            mp[curr] = tmp;
            curr = curr->next;
        }
        Node* old = head;
        curr = mp[old];
        while(old){
            curr->next = mp[old->next];
            curr->random = mp[old->random];
            curr = curr->next;
            old = old->next;
        }
        return mp[head]; 
    }
};
