class Solution {
public:
    int maximumGain(string s, int x, int y) {
        if(x<y){
            swap(x,y);
            reverse(s.begin(),s.end());
        }
        int aCount=0,bCount=0,totalPoints=0;
        for(int i=0;i<s.size();i++){
            char cur=s[i];
            if(cur=='a') aCount++;
            else if(cur=='b'){
                if(aCount>0){
                    aCount--;
                    totalPoints+=x;
                }else{
                    bCount++;
                }
            }else{
                totalPoints+=min(aCount,bCount)*y;
                aCount=bCount=0;
            }
        }
        totalPoints+=min(aCount,bCount)*y;
        return totalPoints;
    }
};