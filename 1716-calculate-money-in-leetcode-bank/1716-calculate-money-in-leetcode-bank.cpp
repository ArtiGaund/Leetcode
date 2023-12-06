class Solution {
public:
    int totalMoney(int n) {
        int k=n/7;
        int F=28;
        int L=28+(k-1)*7;
        int sum=k*(F+L)/2;
        int monday=1+k;
        int finalWeek=0;
        for(int d=0;d<n%7;d++)
            finalWeek+=monday+d;
        return sum+finalWeek;
    }
};