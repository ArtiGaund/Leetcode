class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> max_h;
        for(auto a:stones) max_h.push(a);
        while(max_h.size()>1)
        {
            int first=max_h.top();
            max_h.pop();
            int sec=max_h.top();
            max_h.pop();
            if(first!=sec)
                max_h.push(abs(first-sec));
        }
        int res=max_h.empty()?0:max_h.top();
        return res;
    }
};