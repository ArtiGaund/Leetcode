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
class FindElements {
public:
unordered_set<int> seen;
    FindElements(TreeNode* root) {
        bfs(root);
    }
    bool find(int target){
        return seen.find(target)!=seen.end();
    }
    void bfs(TreeNode *root){
        queue<TreeNode*> q;
        root->val=0;
        q.push(root);
        while(!q.empty()){
            TreeNode *cur=q.front();
            q.pop();
            seen.insert(cur->val);
            if(cur->left){
                cur->left->val=cur->val*2+1;
                q.push(cur->left);
            }
            if(cur->right){
                cur->right->val=cur->val*2+2;
                q.push(cur->right);
            }
        }
    }
    
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */