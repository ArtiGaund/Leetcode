class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());
        deque<int> q;
        for(int num:piles) q.push_back(num);
        int res=0;
        while(!q.empty()){
            q.pop_back(); //alice;
            res+=q.back(); //me
            q.pop_back();
            q.pop_front(); //bob
        }
        return res;
    }
};