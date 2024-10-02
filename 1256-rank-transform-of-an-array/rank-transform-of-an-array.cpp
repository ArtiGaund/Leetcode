class Solution {
public:
    static bool comp(pair<int,int> &a,pair<int,int> &b){
        return a.second<b.second;
    }
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n=arr.size();
        if(n==0) return {};
        vector<pair<int,int>> temp;
        for(int i=0;i<n;i++) temp.push_back({arr[i],i});
        sort(temp.begin(),temp.end());
        int x=temp[0].first;
        int rank=1;
        temp[0].first=rank;
        for(int i=1;i<n;i++){
            if(temp[i].first==x) temp[i].first=rank;
            else{
                rank++;
                x=temp[i].first;
                temp[i].first=rank;
            }
        }
        sort(temp.begin(),temp.end(),comp);
        vector<int> res;
        for(int i=0;i<n;i++) res.push_back(temp[i].first);
        return res;
    }
};