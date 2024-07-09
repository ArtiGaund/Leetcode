class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int nextIdleTime=0;
        long long netWaitTime=0;
        for(auto c:customers){
            nextIdleTime=max(c[0],nextIdleTime)+c[1];
            netWaitTime+=nextIdleTime-c[0];
        }
        double avgWaitTime=static_cast<double>(netWaitTime)/customers.size();
        return avgWaitTime;
    }
};