class Solution {
public:
    string smallestNumber(string pattern) {
        int n=pattern.size();
        int maxSoFar=0,curMax=0,temp;
        vector<int> arrD(n+1,0);
        for(int i=n-1;i>=0;i--){
            if(pattern[i]=='D') arrD[i]=arrD[i+1]+1;
        }
            string res="";
            for(int pos=0;pos<=n;pos++){
                if(pattern[pos]=='I'){
                    maxSoFar++;
                    res+='0'+maxSoFar;
                    maxSoFar=max(maxSoFar,curMax);
                    curMax=0;
                }else{
                    temp=1+maxSoFar+arrD[pos];
                    res+='0'+temp;
                    curMax=max(curMax,temp);
                }
            }
        return res;
    }
};