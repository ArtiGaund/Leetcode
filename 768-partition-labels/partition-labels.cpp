class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> partitionSizes;
        int lastOccur[26]={0},firstOccur[26]={0};
        int start=0,end=0;
        for(int i=0;i<s.size();i++) lastOccur[s[i]-'a']=i;
        for(int i=0;i<s.size();i++){
            if(!firstOccur[s[i]-'a']){
                firstOccur[s[i]-'a']=i;
            }
            if(end<firstOccur[s[i]-'a']){
                partitionSizes.push_back(end-start+1);
                start=i;
                end=i;
            }
            end=max(end,lastOccur[s[i]-'a']);
        }
        if(end-start+1>0){
            partitionSizes.push_back(end-start+1);
        }
        return partitionSizes;

    }
};