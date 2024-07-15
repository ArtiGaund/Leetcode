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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_set<int> children,parents;
        unordered_map<int,vector<pair<int,int>>> parToChild;
        for(auto d:descriptions){
            int par=d[0],child=d[1],isLeft=d[2];
            parents.insert(par);
            parents.insert(child);
            children.insert(child);
            parToChild[par].emplace_back(child,isLeft);
        }
        for(auto it=parents.begin();it!=parents.end();){
            if(children.find(*it)!=children.end()){
                it=parents.erase(it);
            }else ++it;
        }
        TreeNode *root=new TreeNode(*parents.begin());
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode *par=q.front();
            q.pop();
            for(auto child:parToChild[par->val]){
                int childVal=child.first,isLeft=child.second;
                TreeNode *temp=new TreeNode(childVal);
                q.push(temp);
                if(isLeft==1) par->left=temp;
                else par->right=temp;
            }
        }
        return root;
    }
};