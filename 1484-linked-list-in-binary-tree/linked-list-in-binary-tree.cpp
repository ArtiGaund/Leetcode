/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool isMatch(TreeNode *node,ListNode *list){
        stack<pair<TreeNode*,ListNode*>> st;
        st.push({node,list});
        while(!st.empty()){
            auto [curNode,curList] = st.top();
            st.pop();
            while(curNode and curList){
                if(curNode->val!=curList->val) break;
                curList=curList->next;
                if(curList){
                    if(curNode->left) st.push({curNode->left,curList});
                    if(curNode->right) st.push({curNode->right,curList});
                    break;
                }
            }
            if(!curList) return true;
        }
        return false;
        
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(!root) return false;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode *node=st.top();
            st.pop();
            if(isMatch(node,head)) return true;
            if(node->left) st.push(node->left);
            if(node->right) st.push(node->right);
        }
        return false;
    }
};