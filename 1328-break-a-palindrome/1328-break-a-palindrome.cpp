class Solution {
public:
    string breakPalindrome(string p) {
        int n = p.size();
        string ans = "";
        for(int i = 0 ; i < n ; i++){
            char lol = p[i];
            for(char c = 'a' ; c <= 'z' ; c++){
                p[i] = c;
                if(c != p[n - i - 1]){
                    if(ans.size() == 0 || ans > p){
                        ans = p;
                    }
                }
                p[i] = lol;
            }
        }
        return ans;
    }
};