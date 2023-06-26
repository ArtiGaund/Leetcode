class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int cand) {
        long long res=0;
        int n=costs.size();
        if(n<=2*cand)
        {
            sort(costs.begin(),costs.end());
            for(int i=0;i<k;i++)
                res+=costs[i];
        }
        else
        {
            priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
            int i=0,j=n-cand;
            for(i=0;i<cand;i++)
            {
                pq.push({costs[i],i});
                pq.push({costs[n-i-1],n-i-1});
            }
            i--;
            while(k and i<j)
            {
                auto v=pq.top();
                pq.pop();
                long long temp=v[0];
                int index=v[1];
                res+=temp;
                k--;
                if(index<=i)
                {
                    i++;
                    if(i<j)
                        pq.push({costs[i],i});
                }
                else
                {
                    j--;
                    if(i<j) pq.push({costs[j],j});
                }
            }
            while(k)
            {
                res+=pq.top()[0];
                pq.pop();
                k--;
            }
        }
        return res;
    }
};