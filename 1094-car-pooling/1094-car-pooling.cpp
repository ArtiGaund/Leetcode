class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> count(1001);
        for(auto it:trips)
        {
            count[it[1]]+=it[0];
            count[it[2]]-=it[0];
        }
        int load=0;
        for(int i=0;i<1001 and load<=capacity;i++)
        {
            load+=count[i];
            if(load>capacity) return false;
        }
        return true;
    }
};