class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> res;
        for(int i=1;i<arr.size();i++)
            arr[i]^=arr[i-1];
        for(const auto q:queries){
            if(q[0]>0){
                res.push_back(arr[q[0]-1]^arr[q[1]]);
            }
            else res.push_back(arr[q[1]]);
        }
        return res;
    }
};