class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int,int> mp;
        int maxVal=0;
        for(int i=1;i<=n;i++){
            int key=0,i0=i;
            while(i0){
                key+=i0%10;
                i0/=10;
            }
            mp[key]++;
            maxVal=max(maxVal,mp[key]);
        }
        int count=0;
        for(auto it:mp){
            if(it.second==maxVal) count++;
        }
        return count;
    }
};