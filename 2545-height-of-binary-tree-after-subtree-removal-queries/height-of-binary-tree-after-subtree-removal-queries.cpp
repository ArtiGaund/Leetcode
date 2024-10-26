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
    int dfs(TreeNode *node,int level,vector<int> &nodeDepths,vector<int> &subtreeHeights,vector<int> &firstLargestHeight,vector<int> &secondLargestHeight){
        if(node==nullptr) return 0;
        nodeDepths[node->val]=level;
        int leftHeight=dfs(node->left,level+1,nodeDepths,subtreeHeights,firstLargestHeight,secondLargestHeight);
        int rightHeight=dfs(node->right,level+1,nodeDepths,subtreeHeights,firstLargestHeight,secondLargestHeight);
        int curHeight=1+max(leftHeight,rightHeight);
        subtreeHeights[node->val]=curHeight;
        if(curHeight>firstLargestHeight[level]){
            secondLargestHeight[level]=firstLargestHeight[level];
            firstLargestHeight[level]=curHeight;
        }else if(curHeight>secondLargestHeight[level]){
            secondLargestHeight[level]=curHeight;
        }
        return curHeight;
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        int n=100000;
        vector<int> nodeDepths(n+1,0);
        vector<int> subtreeHeights(n+1,0);
        vector<int> firstLargestHeight(n+1,0);
        vector<int> secondLargestHeight(n+1,0);
        dfs(root,0,nodeDepths,subtreeHeights,firstLargestHeight,secondLargestHeight);
        vector<int> res;
        res.reserve(queries.size());
        for(int q:queries){
            int level=nodeDepths[q];
            if(subtreeHeights[q]==firstLargestHeight[level]){
                res.push_back(level+secondLargestHeight[level]-1);
            }else{
                res.push_back(level+firstLargestHeight[level]-1);
            }
        }
        return res;
    }
};