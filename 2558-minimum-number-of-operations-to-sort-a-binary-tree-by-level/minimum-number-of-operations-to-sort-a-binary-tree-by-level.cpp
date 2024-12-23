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
    const int SHIFT = 20;
    const int MASK = 0xFFFFF;
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int swaps=0;
        while(!q.empty()){
            int size=q.size();
            vector<long long> temp(size);
            for(int i=0;i<size;i++){
                TreeNode *node = q.front();
                q.pop();
                temp[i]=(static_cast<long long>(node->val)<<SHIFT)+i;
                if(node->left!=nullptr) q.push(node->left);
                if(node->right!=nullptr) q.push(node->right);
            }
            sort(temp.begin(),temp.end());
            for(int i=0;i<size;i++){
                int origPos=static_cast<int>(temp[i]&MASK);
                if(origPos!=i){
                    swap(temp[i],temp[origPos]);
                    swaps++;
                    i--;
                }
            }
        }
        return swaps;
    }
};