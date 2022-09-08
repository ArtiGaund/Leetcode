class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        // Create data to record only results that we need, during radix sort
        //data[trimming level][order after trimming & sorting (k)] = what we should record
        unordered_map<int, unordered_map<int, int>> data;
        int tmax = -1; // most significant digit that we need to sort by
        for (auto& q : queries) {
            data[q[1]][q[0]] = 0;
            tmax = max(tmax, q[1]);
        }
        
        vector<int> inds(nums.size());     // indices of numbers in nums after each sorting step
        iota(inds.begin(), inds.end(), 0); // indices are initially 0, 1, 2, ...
        const int len = nums[0].length();
        for (int t=1; t<=tmax; t++) {
            // we are going to put indices of numbers in nums in the buckets
            // depending on their t-th digit
            vector<vector<int>> buckets(10);
            
            // Put indices in buckests
            // indice "i" goes into bucket b where b is the t-th digit of nums[i], i.e. nums[i][len - t]-'0']
            for (auto& i : inds) {
                buckets[nums[i][len - t]-'0'].push_back(i);
            }
            
            // Reorder vector of indices by getting them out of buckets in order
            int cnt = 0;
            for (auto& b : buckets) {
                for (auto& i : b) {
                    inds[cnt++] = i;
                }
            }
            
            // Now numbers are sorted by t-th digit
            // Record results for this trimming level
            if (data.find(t) != data.end()) {
                for (auto& q : data[t]) {
                    q.second = inds[q.first-1];
                }
            }
        }
        
        // Convert recorded data to requested format
        vector<int> out(queries.size());
        for (int i=0; i<queries.size(); i++) {
            out[i] = data[queries[i][1]][queries[i][0]];
        }
        
        return out;
    }
};