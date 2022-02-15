class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()==0) return intervals;
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> merge;
        vector<int> prev=intervals[0];
        for(int i=1;i<intervals.size();i++)
        {
            vector<int> cur=intervals[i];
            if(intervalOverlap(prev,cur))
                prev[1]=max(prev[1],cur[1]);
            else
            {
                merge.push_back(prev);
                prev=cur;
            }
        }
        merge.push_back(prev);
        return merge;
    }
    bool intervalOverlap(vector<int> &a,vector<int> &b)
    {
        if(b[0]>a[1]) return false;
        return true;
    }
};