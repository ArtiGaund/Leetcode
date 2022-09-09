class Solution {
public:
    static bool comp(vector<int> &a,vector<int> &b)
    {
        if(a[0]!=b[0]) return a[0]>b[0];
        return a[1]<b[1];
    }
    int numberOfWeakCharacters(vector<vector<int>>& p) {
        sort(p.begin(),p.end(),comp);
        int max_val=INT_MIN;
        int weak=0;
        for(auto a:p)
        {
            if(max_val>a[1]) weak++;
            else max_val=a[1];
        }
        return weak;
    }
};