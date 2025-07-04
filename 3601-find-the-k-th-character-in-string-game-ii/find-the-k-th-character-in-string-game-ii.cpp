class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        int res=0;
        k--;
        for(int i=__lg(k);i>=0;i--){
            if(k>>i &1){
                res+=operations[i];
            }
        }
        return 'a'+(res%26);
    }
};