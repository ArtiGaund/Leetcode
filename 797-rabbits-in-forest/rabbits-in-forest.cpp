class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> mp;
        for(int i:answers) mp[i]++;
        int total=0;
        for(auto it:mp){
            total+=ceil((double)it.second/(it.first+1))*(it.first+1);
        }
        return total;
    }
};