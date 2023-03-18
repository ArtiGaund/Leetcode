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
        if(root==nullptr or p==nullptr or q==nullptr) return root;
        stack<TreeNode*> st;
        bool findOne=false;
        TreeNode *prev=nullptr,*res=root;
        while(true)
        {
            if(root)
            {
                st.push(root);
                root=root->left;
            }
            else
            {
                if(st.empty()) break;
                TreeNode *cur=st.top();
                if(cur->right==nullptr or cur->right==prev)
                {
                    if(cur==p or cur==q)
                    {
                        if(findOne) break;
                        else
                        {
                            findOne=true;
                            res=cur;
                        }
                    }
                    st.pop();
                    if(cur==res) res=st.top();
                    prev=cur;
                }
                else root=cur->right;
            }
        }
        return res;
    }
};