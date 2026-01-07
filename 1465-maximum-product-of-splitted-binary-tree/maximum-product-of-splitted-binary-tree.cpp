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
vector<int> arr;
int dfs(TreeNode* root){
    if(root==nullptr) return 0;
    int cur=arr.size();
    arr.push_back(root->val);
    arr[cur]+=dfs(root->left)+dfs(root->right);
    return arr[cur];
}
    int maxProduct(TreeNode* root) {
        int mod=1e9+7;
        long long res=0;
        dfs(root);
        for(int a:arr){
            res=max((long long)a*(arr[0]-a),res);
        }
        return res%mod;
    }
};