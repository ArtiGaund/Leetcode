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
    int maxLevelSum(TreeNode* root) {
        if(root==nullptr) return 0;
        queue<TreeNode*> q;
        q.push(root);
        long long int max_val=INT_MIN;
        int res_level;
        int level=0;
        while(!q.empty()){
            level++;
            int size=q.size();
            long long int sum=0;
            for(int i=0;i<size;i++){
                TreeNode *cur=q.front();
                q.pop();
                sum+=cur->val;
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
            if(max_val<sum){
                res_level=level;
                max_val=sum;
            }
        }
        return res_level;
    }
};