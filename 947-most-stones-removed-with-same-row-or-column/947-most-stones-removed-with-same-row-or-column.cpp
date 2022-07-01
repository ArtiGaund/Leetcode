class Solution {
public:
    struct subset
    {
        int parent,rank;
    };
    int find(vector<subset> &Parent,int x)
    {
        if(Parent[x].parent==-1) return x;
        return find(Parent,Parent[x].parent);
    }
    void unionset(vector<subset> &Parent,int a,int b)
    {
        int x=find(Parent,a);
        int y=find(Parent,b);
        if(x!=y)
        {
            if(Parent[x].rank>Parent[y].rank) Parent[y].parent=x;
            else if(Parent[x].rank<Parent[y].rank) Parent[x].parent=y;
            else
            {
                Parent[y].parent=x;
                Parent[x].rank++;
            }
        }
        return;
    }
    bool isSameRow(vector<vector<int>> &stones,int i,int j)
    {
        return stones[i][0]==stones[j][0];
    }
    bool isSameCol(vector<vector<int>> &stones,int i,int j)
    {
        return stones[i][1]==stones[j][1];
    }
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        vector<subset> Parent(n,{-1,0});
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(isSameRow(stones,i,j) or isSameCol(stones,i,j))
                {
                    unionset(Parent,i,j);
                }
            }
        }
        int group=0;
        for(int i=0;i<n;i++)
            if(Parent[i].parent==-1) group++;
        return n-group;
    }
};