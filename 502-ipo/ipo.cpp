class Solution {
public:
    struct capitalComp
    {
        bool operator()(const pair<int,int> &x,const pair<int,int> &y)
        {
            return x.first>y.first;
        }
    };
    struct profitComp
    {
        bool operator()(const pair<int,int> &x,const pair<int,int> &y)
        {
            return y.first>x.first;
        }
    };
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
         int n=profits.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,capitalComp> minHeap;
        priority_queue<pair<int,int>,vector<pair<int,int>>,profitComp> maxHeap;
        for(int i=0;i<n;i++)
            minHeap.push({capital[i],i});
        int availCap=w;
        for(int i=0;i<k;i++)
        {
            while(!minHeap.empty() and minHeap.top().first<=availCap)
            {
                int capIndex=minHeap.top().second;
                minHeap.pop();
                maxHeap.push({profits[capIndex],capIndex});
            }
            if(maxHeap.empty()) break;
            availCap+=maxHeap.top().first;
            maxHeap.pop();

        }
        return availCap;
    }
};