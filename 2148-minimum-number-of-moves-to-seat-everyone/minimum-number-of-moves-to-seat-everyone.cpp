class Solution {
public:
    int findMax(vector<int> temp){
        int m=0;
        for(int num:temp){
            if(num>m) m=num;
        }
        return m;
    }
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        int maxPos = max(findMax(seats),findMax(students));
        vector<int> diff(maxPos,0);
        for(int pos:seats) diff[pos-1]++;
        for(int pos:students) diff[pos-1]--;
        int moves=0,unmatched=0;
        for(int d:diff){
            moves+=abs(unmatched);
            unmatched+=d;
        }
        return moves;
    }
};