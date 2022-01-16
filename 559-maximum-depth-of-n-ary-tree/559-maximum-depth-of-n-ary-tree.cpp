/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        if(root==nullptr) return 0;
        queue<Node*> q;
        q.push(root);
        int depth=0;
        while(!q.empty())
        {
            depth++;
            int size=q.size();
            while(size--)
            {
                Node *cur=q.front();
                q.pop();
                for(auto it:cur->children) q.push(it);
            }
        }
        return depth;
    }
};