/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        Node* newstart = new Node(node->val);
        unordered_map<Node*, Node*> nodemap;
        nodemap[node] = newstart;
        queue<Node*> nodequeue;
        nodequeue.push(node);
        while(!nodequeue.empty()){
            Node* cur = nodequeue.front();
            nodequeue.pop();
            vector<Node*> nei = cur->neighbors;
            for(Node* n : nei){
                if(nodemap.find(n) == nodemap.end()){
                    Node* newn = new Node(n->val);
                    nodequeue.push(n);
                    nodemap[n] = newn;
                }
                nodemap[cur]->neighbors.push_back(nodemap[n]);
            }
        }
        return nodemap[node];
    }
};
