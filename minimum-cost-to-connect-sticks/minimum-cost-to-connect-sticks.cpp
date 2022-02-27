class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int,vector<int>,greater<int>> maxH;
        for(int a:sticks) maxH.push(a);
        int minCost=0;
        while(maxH.size()>=2)
        {
            int first=maxH.top();
            maxH.pop();
            int second=maxH.top();
            maxH.pop();
            int combined=first+second;
            maxH.push(combined);
            minCost+=combined;
        }
        return minCost;
    }
};