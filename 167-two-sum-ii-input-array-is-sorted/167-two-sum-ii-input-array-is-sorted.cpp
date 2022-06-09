class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int,int> mp;
        for(int i=0;i<numbers.size();i++)
        {
            if(mp.find(target-numbers[i])!=mp.end())
            {
                int a=mp[target-numbers[i]];
                int b=i+1;
                return {a,b};
            }
            mp[numbers[i]]=i+1;
        }
        return {};
    }
};