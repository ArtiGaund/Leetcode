class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalTank=0,curTank=0,startingStation=0;
        for(int i=0;i<gas.size();i++)
        {
            int netCost=gas[i]-cost[i];
            curTank+=netCost;
            totalTank+=netCost;
            if(curTank<0)
            {
                startingStation=i+1;
                curTank=0;
            }
        }
        return (totalTank<0?-1:startingStation);
    }
};