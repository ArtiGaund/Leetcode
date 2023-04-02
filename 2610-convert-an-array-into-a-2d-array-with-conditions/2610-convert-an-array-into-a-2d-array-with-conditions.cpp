class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto a:nums) mp[a]++;
        vector<vector<int>> res;
        while(mp.size())
        {
            vector<int> temp;
            for(auto it:mp) temp.push_back(it.first);
            for(int i:temp)
            {
                if(!--mp[i]) mp.erase(i);
            }
            res.push_back(temp);
        }
        return res;
    }
};