class Solution {
public:
    int binarySearch(vector<int> &v)
    {
        int low=0,high=v.size();
        while(low<high)
        {
            int mid=low+(high-low)/2;
            if(v[mid]==1) low=mid+1;
            else high=mid;
        }
        return low;
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>> maxH;
        for(int i=0;i<mat.size();i++)
        {
            int count=binarySearch(mat[i]);
            maxH.push({count,i});
            if(i>=k) maxH.pop();
        }
        vector<int> res(maxH.size());
	for(int i = res.size()-1; i >= 0; --i) {
		res[i] = maxH.top().second;
	    maxH.pop();
	}
        return res;
    }
};