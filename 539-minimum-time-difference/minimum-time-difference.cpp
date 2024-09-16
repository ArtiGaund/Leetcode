class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<bool> minutes(24*60,false);
        for(string time: timePoints){
            int h=stoi(time.substr(0,2));
            int m=stoi(time.substr(3));
            int min=h*60+m;
            if(minutes[min]) return 0;
            minutes[min]=true;
        }
        int prev=INT_MAX,first=INT_MAX,last=INT_MAX,res=INT_MAX;
        for(int i=0;i<24*60;i++){
            if(minutes[i]){
                if(prev!=INT_MAX) res=min(res,i-prev);
                prev=i;
                if(first==INT_MAX) first=i;
                last=i;
            }
        }
        return min(res,24*60-last+first);
    }
};