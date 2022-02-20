class Solution {
public:
    vector<long long> res;
    vector<long long> maximumEvenSplit(long long finalSum) {
        if(finalSum%2!=0) return res;
        dfs(finalSum,2);
        return res;
    }
    bool dfs(long long target,long long i)
    {
        if(target==0) return true;
        if(target<i) return false;
        res.push_back(i);
        if(dfs(target-i,i+2)) return true; //include
        res.pop_back();
        return dfs(target,i+2); //exclude
    }
};