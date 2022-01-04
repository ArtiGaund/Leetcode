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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        stack<TreeNode*> st;
        st.push(s);
        while(!st.empty())
        {
            TreeNode *cur=st.top();
            st.pop();
            if(cur->val==t->val)
            {
                if(isIdentical(cur,t)) return true;
            }
            if(cur->right) st.push(cur->right);
            if(cur->left) st.push(cur->left);
        }
        return false;
    }
    bool isIdentical(TreeNode *s,TreeNode* t)
    {
        stack<TreeNode*> s1,s2;
        s1.push(s);
        s2.push(t);
        while(!s1.empty() and !s2.empty())
        {
            TreeNode *cur1=s1.top();
            s1.pop();
            TreeNode* cur2=s2.top();
            s2.pop();
            if(cur1==nullptr and cur2==nullptr) continue;
            if((cur1==nullptr and cur2!=nullptr) or (cur1!=nullptr and cur2==nullptr)) return false;
            if(cur1->val!=cur2->val) return false;
            s1.push(cur1->right);
            s2.push(cur2->right);
            s1.push(cur1->left);
            s2.push(cur2->left);
        }
        return true;
    }
};