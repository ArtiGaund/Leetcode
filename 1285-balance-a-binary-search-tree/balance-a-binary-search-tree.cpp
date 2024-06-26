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
    void rightRotate(TreeNode *par,TreeNode *node){
        TreeNode *temp=node->left;
        node->left=temp->right;
        temp->right=node;
        par->right=temp;
    }
    void leftRotate(TreeNode *par,TreeNode *node){
        TreeNode *temp=node->right;
        node->right=temp->left;
        temp->left=node;
        par->right=temp;
    }
    void makeRotations(TreeNode *par,int count){
       TreeNode *cur=par;
        for(int i=0;i<count;i++){
            TreeNode *temp=cur->right;
            leftRotate(cur,temp);
            cur=cur->right;
        }
    }
    TreeNode* balanceBST(TreeNode* root) {
        if(!root) return nullptr;
        TreeNode *temp=new TreeNode(0);
        temp->right=root;
        TreeNode *cur=temp;
        while(cur->right){
            if(cur->right->left) rightRotate(cur,cur->right);
            else cur=cur->right;
        }
        int count=0;
        cur=temp->right;
        while(cur){
            count++;
            cur=cur->right;
        }
        int m=pow(2,floor(log2(count+1)))-1;
        makeRotations(temp,count-m);
        while(m>1){
            m/=2;
            makeRotations(temp,m);
        }
        TreeNode *res=temp->right;
        delete temp;
        return res;
    }
};