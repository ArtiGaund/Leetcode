create a parent array using bfs for our elements
and then perform normal traversal using this parent array.
even levels  seek  last element of queue and push children in the front
and the opposite for odd levels.
​
(do again)
sol 2) log n
vector<int> pathInZigZagTree(int label) {
vector<int> res;
res.push_back(label); //take bottom up approach so the label itself is included
int height=log2(label); //height of label from root
while(height!=0)
{
int left=pow(2,height-1); //rank of left limit of prev level
int right=pow(2,height)-1; //rank of right limit of prev level
label=left+(right-label/2); //prev level is sorted in diff order than cur level so new
// level is adjusted
res.push_back(label);
height--;
}
reverse(res.begin(),res.end());
return res;
}