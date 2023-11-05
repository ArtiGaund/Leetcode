class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int maxEle = arr[0];
        for(int i=1;i<arr.size();i++) maxEle=max(maxEle,arr[i]);
        int cur=arr[0];
        int winStreak=0;
        for(int i=1;i<arr.size();i++){
            int opponent = arr[i];
            if(cur>opponent) winStreak++;
            else{
                cur=opponent;
                winStreak=1;
            }
            if(winStreak == k or cur==maxEle) return cur;
        }
        return -1;
    }
};