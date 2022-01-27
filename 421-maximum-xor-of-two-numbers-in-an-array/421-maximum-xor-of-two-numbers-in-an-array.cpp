class Solution {
public:
    struct trie{
        trie *child[2]={};
    };
    void insert(trie *root,int num)
        {
            trie *cur=root;
            for(int i=31;i>=0;i--)
            {
                int bit=(num>>i)&1;
                if(cur->child[bit]==nullptr) cur->child[bit]=new trie();
                cur=cur->child[bit];
            }
        }
    int findMax(trie *root,int num)
        {
            trie *cur=root;
            int ans=0;
            for(int i=31;i>=0;i--)
            {
                int bit=(num>>i)&1;
                if(cur->child[1-bit]!=nullptr) 
                {
                    cur=cur->child[1-bit];
                    ans |= (1<<i);
                }
                else cur=cur->child[bit];
            }
            return ans;
        }
    int findMaximumXOR(vector<int>& nums) {
        trie *root=new trie();
        for(int x:nums)
            insert(root,x);
        int ans=0;
        for(int x:nums)
        {
            int res=findMax(root,x);
            ans=max(ans,res);
        }
        return ans;
    }
};