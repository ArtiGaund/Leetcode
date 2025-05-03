class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int res=INT_MAX;
        int face[7]={};
        for(int i=0;i<tops.size();i++){
            face[tops[i]]++;
            if(bottoms[i]!=tops[i]) face[bottoms[i]]++;
        }
        for(int x=1;x<=6;x++){
            if(face[x]<tops.size()) continue;
            int maintainTop=0,maintainBottom=0;
            bool possible=true;
            for(int i=0;i<tops.size();i++){
                if(tops[i]!=x and bottoms[i]!=x){
                    possible=false;
                    break;
                }
                if(tops[i]!=x) maintainTop++;
                if(bottoms[i]!=x) maintainBottom++;
            }
            if(possible)
                res=min(res,min(maintainTop,maintainBottom));
        }
        return res==INT_MAX?-1:res;
    }
};