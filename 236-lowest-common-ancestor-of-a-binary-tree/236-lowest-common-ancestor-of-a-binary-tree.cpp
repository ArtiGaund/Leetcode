/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr or root==p or root==q) return root;
        stack<TreeNode*> s;
        TreeNode *prev=nullptr,*res=root;
        bool findone=false;
        while(true)
        {
            if(root)
            {
                s.push(root);
                root=root->left;
            }
            else
            {
                if(s.empty()) break;
                TreeNode *cur=s.top();
                if(cur->right==nullptr or cur->right==prev)
                {
                    if(cur==p or cur==q)
                    {
                        if(findone) break;
                        else
                        {
                            findone=true;
                            res=cur;
                        }
                    }
                    s.pop();
                    if(cur==res) res=s.top();
                    prev=cur;
                }
                else root=cur->right;
            }
        }
        return res;
    }
};