class Solution {
public:
    // pair<int,pair<int,int>>
    struct valComp
    {
        bool operator()(const pair<int,pair<int,int>> &x,const pair<int,pair<int,int>> &y)
        {
            return x.first>y.first;
        }
    };
    int kthSmallest(vector<vector<int>>& matrix, int k) {
      priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,valComp> minHeap;
        for(auto i=0;i<matrix.size();i++)
        {
            if(!matrix[i].empty()) minHeap.push({matrix[i][0],{i,0}});
        }
        int numCount=0,res=0;
        while(!minHeap.empty())
        {
            auto cur=minHeap.top();
            minHeap.pop();
            res=cur.first;
            if(++numCount==k) break;
            cur.second.second++;
            if(matrix[cur.second.first].size()>cur.second.second)
            {
                cur.first=matrix[cur.second.first][cur.second.second];
                minHeap.push(cur);
            }
        }
        return res;
    }
};