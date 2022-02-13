class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int,vector<int>,greater<int>> minH;
        for(int a:sticks) minH.push(a);
        int minCost=0;
        while(minH.size()>=2)
        {
            int f=minH.top();
            minH.pop();
            int s=minH.top();
            minH.pop();
            int combined=f+s;
            minCost+=combined;
            minH.push(combined);
        }
        return minCost;
    }
};