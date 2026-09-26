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
    unordered_map<Node*, Node*> cloned;

    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }

        // If we've already cloned this node, return the clone
        if (cloned.count(node)) {
            return cloned[node];
        }

        // Create a copy of the current node
        Node* copy = new Node(node->val);

        // Remember the clone BEFORE visiting neighbors
        cloned[node] = copy;

        // Clone all neighbors
        for (Node* neighbor : node->neighbors) {
            copy->neighbors.push_back(cloneGraph(neighbor));
        }

        return copy;
    }
};