class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        unordered_set<char> vowels{'a','e','i','o','u'};
        vector<int> prefixSum(words.size());
        int sum=0;
        for(int i=0;i<words.size();i++){
            string cur=words[i];
            if(vowels.count(cur[0]) and vowels.count(cur[cur.size()-1])){
                sum++;
            }
            prefixSum[i]=sum;
        }
        vector<int> res(queries.size());
        for(int i=0;i<queries.size();i++){
            vector<int> curQ=queries[i];
            res[i]=prefixSum[curQ[1]]-(curQ[0]==0?0:prefixSum[curQ[0]-1]);
        }
        return res;
    }
};