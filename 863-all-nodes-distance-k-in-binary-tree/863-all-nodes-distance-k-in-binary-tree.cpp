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
    // 1) implement function that gets all child with dis k from target
    // 2) find target node through backward traversal to put parents in stack
    // 3) find each level parent, call the fun implemented in first step with correct dis k-level- 
    // -1 and correct sub child
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
       stack<TreeNode*> s;
        while(root and root->val!=target->val)
        {
            s.push(root);
            if(root->left) root=root->left;
            else if(root->right) root=root->right;
            else
            {
                s.pop();
                while(!s.empty() and (s.top()->right==nullptr or s.top()->right==root))
                {
                    root=s.top();
                    s.pop();
                }
                if(!s.empty()) root=s.top()->right;
            }
        }
        vector<int> res=disKChild(target,k);
        int c=1;
        while(!s.empty() and c<k)
        {
            TreeNode *cur=s.top();
            s.pop();
            vector<int> v;
            if(cur->left==root) v=disKChild(cur->right,k-c-1);
            else v=disKChild(cur->left,k-c-1);
            root=cur;
            res.insert(res.end(),v.begin(),v.end());
            c++;
        }
        if(c==k and !s.empty()) res.push_back(s.top()->val);
        return res;
    }
    vector<int> disKChild(TreeNode *root,int k)
    {
        if(root==nullptr) return {};
        if(k==0) return {root->val};
        vector<int> left=disKChild(root->left,k-1);
        vector<int> right=disKChild(root->right,k-1);
        vector<int> res;
        if(left.size()>0) res.insert(res.end(),left.begin(),left.end());
        if(right.size()>0) res.insert(res.end(),right.begin(),right.end());
        return res;
    }
};