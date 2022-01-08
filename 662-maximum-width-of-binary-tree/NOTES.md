Sol1) Binary tree repesent array. If the index of a node is i,the indices of its two child are 2*i and 2*i+1. Use 2 array to store leftmost node and rightmost node in each level. for each level, width is end[level]-start[level]+1.
int findWidth(TreeNode* root)
{
vector<pair<int,int>> v;
return dfs(root,0,1,v);
}
void dfs(TreeNode* root,int depth,int width,vector<pair<int,int>> &v)
{
if(!root) return;
if(depth==v.size()) v.pb({width,width});
else v[depth].second=width;
return max({v[depth].second-v[depth].first+1,dfs(root->left,depth+1,2*width,v), dfs(root->right,depth+1,2*width+1,v)});
}
Sol2) using only single array left to put the left most node
int widthOfBinaryTree(TreeNode* root) {
vector<long long int> lefts; // left most nodes at each level;
unsigned long long maxwidth = 0;
dfs(root, 1, 0, lefts, maxwidth);
return maxwidth;
}
void dfs(TreeNode* node,unsigned long long id,unsigned long long depth, vector<long long int>& lefts, unsigned long long& maxwidth) {
if (!node) return;
if (depth >= lefts.size()) lefts.push_back(id);  // add left most node
maxwidth = max(maxwidth, id + 1 - lefts[depth]);
dfs(node->left, id * 2, depth + 1, lefts, maxwidth);
dfs(node->right, id * 2 + 1, depth + 1, lefts, maxwidth);
}