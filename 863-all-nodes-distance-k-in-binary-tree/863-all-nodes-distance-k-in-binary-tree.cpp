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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        stack<TreeNode *> sta;
        while(root&&root->val!=target->val) {
            sta.push(root);
            if(root->left) root = root->left;
            else if(root->right) root=root->right;
            else {
                sta.pop();
                while(!sta.empty() && (sta.top()->right==NULL||sta.top()->right==root)) {
                    root = sta.top();
                    sta.pop();
                }
                if(!sta.empty())root = sta.top()->right;
            }
        }
        
        vector<int> ret = distKChild(target, K);
        
        int cnt = 1;
        while(!sta.empty()&&cnt<K) {
            TreeNode *node = sta.top();
            sta.pop();
            vector<int> vec;
            if(node->left==root) {
                vec = distKChild(node->right, K-cnt-1);
            } else {
                vec = distKChild(node->left, K-cnt-1);
            }
            root = node;
            ret.insert(ret.end(), vec.begin(), vec.end());
            cnt++;
        }
        if(cnt==K&&!sta.empty()) ret.push_back(sta.top()->val);
        return ret;
    }
    
    vector<int> distKChild(TreeNode *node, int K) {
        if(!node) return vector<int>();
        if(K==0) return vector<int>(1, node->val);
        vector<int> left = distKChild(node->left, K-1);
        vector<int> right = distKChild(node->right, K-1);
        vector<int> ret;
        if(left.size()>0) ret.insert(ret.end(), left.begin(), left.end());
        if(right.size()>0) ret.insert(ret.end(), right.begin(), right.end());
        return ret;
    }
};