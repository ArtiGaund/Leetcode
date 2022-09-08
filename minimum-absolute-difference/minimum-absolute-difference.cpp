class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int minDiff=(arr[1]-arr[0]);
        for(int i=2;i<arr.size();i++)
        {
            int diff=arr[i]-arr[i-1];
            minDiff=min(minDiff,diff);
        }
        vector<vector<int>> res;
        for(int i=1;i<arr.size();i++)
        {
            vector<int> temp;
            if(arr[i]-arr[i-1]==minDiff)
            {
                temp.push_back(arr[i-1]);
                temp.push_back(arr[i]);
                res.push_back(temp);
            }
        }
        return res;
    }
};