class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        vector<int> prefix(n),freq(n+1,0);
        int commonCount=0;
        for(int cur=0;cur<n;cur++){
            if(++freq[A[cur]]==2) commonCount++;
            if(++freq[B[cur]]==2)  commonCount++;
            prefix[cur]=commonCount;
        }
        return prefix;
    }
};