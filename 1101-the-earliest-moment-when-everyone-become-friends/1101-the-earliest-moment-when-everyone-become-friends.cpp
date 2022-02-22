class Solution {
public:
    int earliestAcq(vector<vector<int>>& logs, int N) {
       vector<int> ds(N, -1);
  sort(begin(logs), end(logs));
  for (auto &l : logs) {
      auto i = ds_find(ds, l[1]), j = ds_find(ds, l[2]);
      if (i != j) {
        if (ds[i] > ds[j])
            swap(i, j);
        ds[i] += ds[j];
        ds[j] = i;
        if (-ds[i] == N)
            return l[0];
      }      
  }
  return -1;
    }
   int ds_find(vector<int>& ds, int i) {
  return ds[i] < 0 ? i : ds[i] = ds_find(ds, ds[i]);
}
};