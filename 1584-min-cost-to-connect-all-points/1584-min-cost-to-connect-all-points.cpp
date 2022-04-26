class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        int mstCost=0,edgesUsed=0;
        vector<bool> inMST(n);
        vector<int> minDis(n,INT_MAX);
        minDis[0]=0;
        while(edgesUsed<n)
        {
            int curMinEdge=INT_MAX;
            int curNode=-1;
            for(int node=0;node<n;node++)
            {
                if(!inMST[node] and curMinEdge>minDis[node])
                {
                    curMinEdge=minDis[node];
                    curNode=node;
                }
            }
            mstCost+=curMinEdge;
            edgesUsed++;
            inMST[curNode]=true;
            for(int nextNode=0;nextNode<n;nextNode++)
            {
                int weight=abs(points[curNode][0]-points[nextNode][0])+abs(points[curNode][1]-points[nextNode][1]);
                if(!inMST[nextNode] and minDis[nextNode]>weight)
                    minDis[nextNode]=weight;
            }
        }
        return mstCost;
    }
};