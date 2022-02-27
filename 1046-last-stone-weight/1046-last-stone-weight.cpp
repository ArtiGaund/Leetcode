class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxH;
        for(int a:stones) maxH.push(a);
        while(maxH.size()>1)
        {
            int first=maxH.top();
            maxH.pop();
            int second=maxH.top();
            maxH.pop();
            if(first!=second)
            {
                maxH.push(abs(first-second));
            }
        }
        int res=maxH.empty()?0:maxH.top();
        return res;
    }
};