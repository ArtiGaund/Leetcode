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
       if(node==nullptr) return node;
        unordered_map<Node*,Node*> clone;
        Node *copy=new Node(node->val,{});
        clone[node]=copy;
        queue<Node*> q;
        q.push(node);
        while(!q.empty())
        {
            Node *cur=q.front();
            q.pop();
            for(Node *neighbor:cur->neighbors)
            {
                if(clone.find(neighbor)==clone.end())
                {
                    clone[neighbor]=new Node(neighbor->val,{});
                    q.push(neighbor);
                }
                clone[cur]->neighbors.push_back(clone[neighbor]);
            }
        }
        return copy;
    }
};