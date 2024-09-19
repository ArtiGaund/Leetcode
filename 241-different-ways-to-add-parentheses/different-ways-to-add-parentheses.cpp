class Solution {
public:
    void initializeBaseCases(string expression,vector<vector<vector<int>>> &dp){
        int n=expression.size();
        for(int i=0;i<n;i++){
            if(isdigit(expression[i])){
                int a=expression[i]-'0';
                if(i+1<n and isdigit(expression[i+1])){
                    int b=expression[i+1]-'0';
                    int num=a*10+b;
                    dp[i][i+1].push_back(num);
                }
                dp[i][i].push_back(a);
            }
        }
    }
    void solve(string expression,vector<vector<vector<int>>> &dp,int start,int end){
        for(int split=start;split<=end;split++){
            if(isdigit(expression[split])) continue;
            vector<int> left=dp[start][split-1];
            vector<int> right=dp[split+1][end];
            computeResults(expression[split],left,right,dp[start][end]);
        }
    }
    void computeResults(char op,vector<int> &left,vector<int> &right,vector<int> &res){
        for(int leftVal:left){
            for(int rightVal:right){
                switch(op){
                    case '+':
                        res.push_back(leftVal+rightVal);
                        break;
                    case '-':
                        res.push_back(leftVal-rightVal);
                        break;
                    case '*':
                        res.push_back(leftVal*rightVal);
                        break;
                }
            }
        }
    }
    vector<int> diffWaysToCompute(string expression) {
        int n=expression.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n));
        initializeBaseCases(expression,dp);
        for(int len=3;len<=n;len++){
            for(int start=0;start+len-1<n;start++){
                int end=start+len-1;
                solve(expression,dp,start,end);
            }
        }
        return dp[0][n-1];
    }
};