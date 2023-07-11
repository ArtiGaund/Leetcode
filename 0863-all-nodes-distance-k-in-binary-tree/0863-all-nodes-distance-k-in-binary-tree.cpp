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
    vector<int> distKChild(TreeNode *root,int k)
    {
        if(root==nullptr) return {};
        if(k==0) return {root->val};
        vector<int> left=distKChild(root->left,k-1);
        vector<int> right=distKChild(root->right,k-1);
        vector<int> res;
        if(left.size()>0) res.insert(res.end(),left.begin(),left.end());
        if(right.size()>0) res.insert(res.end(),right.begin(),right.end());
        return res;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        stack<TreeNode*> st;
        while(root and root->val!=target->val)
        {
            st.push(root);
            if(root->left) root=root->left;
            else if(root->right) root=root->right;
            else
            {
                st.pop();
                while(!st.empty() and (st.top()->right==nullptr or st.top()->right==root))
                {
                    root=st.top();
                    st.pop();
                }
                if(!st.empty()) root=st.top()->right;
            }
        }
        vector<int> res=distKChild(target,k);
        int c=1;
        while(!st.empty() and c<k)
        {
            TreeNode *cur=st.top();
            st.pop();
            vector<int> v;
            if(cur->left==root) v=distKChild(cur->right,k-c-1);
            else v=distKChild(cur->left,k-c-1);
            root=cur;
            res.insert(res.end(),v.begin(),v.end());
            c++;
        }
        if(c==k and !st.empty()) res.push_back(st.top()->val);
        return res;
    }
};