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
        if(root==0) return 0;
        queue<Node*> q;
        q.push(root);
        int depth=0;
        while(!q.empty())
        {
            depth++;
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                Node *cur=q.front();
                q.pop();
                for(Node *c:cur->children)
                    q.push(c);
            }
        }
        return depth;
    }
};