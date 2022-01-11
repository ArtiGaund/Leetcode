/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        if(root==nullptr) return 0;
        int rootToLeaf=0,curNo=0;
        deque<pair<TreeNode*,int>> dq;
        dq.push_back({root,0});
        while(!dq.empty())
        {
            pair<TreeNode*,int> p=dq.front();
            dq.pop_front();
            root=p.first;
            curNo=p.second;
            if(root)
            {
                curNo=(curNo<<1)|root->val;
                if(root->left==nullptr and root->right==nullptr)
                    rootToLeaf+=curNo;
                else
                {
                    if(root->right) dq.push_back({root->right,curNo});
                    if(root->left) dq.push_back({root->left,curNo});
                }
            }
        }
        return rootToLeaf;
    }
};