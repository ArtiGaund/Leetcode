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
    TreeNode* recoverFromPreorder(string traversal) {
        stack<TreeNode*> st;
        int index=0;
        while(index<traversal.size()){
            int depth=0;
            while(index<traversal.size() and traversal[index]=='-'){
                depth++;
                index++;
            }
            int val=0;
            while(index<traversal.size() and isdigit(traversal[index])){
                val=val*10+(traversal[index]-'0');
                index++;
            }
            TreeNode* node=new TreeNode(val);
            while(st.size()>depth){
                st.pop();
            }
            if(!st.empty()){
                if(st.top()->left==nullptr){
                    st.top()->left=node;
                }else{
                    st.top()->right=node;
                }
            }
            st.push(node);
        }
        while(st.size()>1){
            st.pop();
        }
        return st.top();
    }
};