pre = root->left->right
in = left->root->right
store in order in mp (val->index) to fetch the position of root in constant time
unordered_map<int,int> mp;
int index;
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
index=0;
for(int i=0;i<inorder.size();i++) mp[inorder[i]]=i;
return constructTree(preorder,0,preorder.size()-1);
}
TreeNode *constructTree(vector<int> &pre,int left,int right)
{
if(left>right) return nullptr;
int rootval=pre[index++];
TreeNode *root=new TreeNode(rootval);
root->left=constructTree(pre,left,mp[rootval]-1);
root->right=constructTree(pre,mp[rootval]+1,right);
return root;
}
TC - O(N) SC - O(N)