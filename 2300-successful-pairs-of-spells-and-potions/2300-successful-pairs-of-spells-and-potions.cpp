class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        vector<int> res;
        int n=spells.size();
        int m=potions.size();
        int maxPotion=potions[m-1];
        for(auto s:spells)
        {
            long long minPotion=ceil((1.0)*success/s);
            if(minPotion>maxPotion)
            {
                res.push_back(0);
                continue;
            }
            auto index=lower_bound(potions.begin(),potions.end(),minPotion)-potions.begin();
            res.push_back(m-index);
        }
        return res;
    }
};