class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq(piles.begin(),piles.end());
        int total=0;
        for(int a:piles) total+=a;
        for(int i=0;i<k;i++)
        {
            int cur=pq.top();
            pq.pop();
            int remove=cur/2;
            total-=remove;
            pq.push(cur-remove);
        }
        return total;
    }
};