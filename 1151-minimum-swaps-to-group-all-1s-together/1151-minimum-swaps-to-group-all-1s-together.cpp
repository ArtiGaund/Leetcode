class Solution {
public:
    int minSwaps(vector<int>& data) {
        int n=data.size();
        for(int i=1;i<n;i++)
            data[i]+=data[i-1];
        if(!data.back()) return 0;
        int ones=data.back(),res=ones-data[ones-1];
        for(int i=ones;i<n;i++)
            res=min(res,ones-(data[i]-data[i-ones]));
        return res;
    }
};