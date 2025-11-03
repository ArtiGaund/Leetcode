class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n=colors.size(),res=0;
        for(int i=0;i<n;i++){
            int j=i;
            while(i+1<n and colors[i+1]==colors[j]) i++;
            if(j!=i){
                int maxEle = *max_element(neededTime.begin()+j,neededTime.begin()+i+1);
                bool flag=false;
                for(int k=j;k<=i;k++){
                    if(neededTime[k]!=maxEle) res+=neededTime[k];
                    else{
                        if(flag) res+=neededTime[k];
                        flag=true;
                    }
                }
            } 
        }
        return res;
    }
};