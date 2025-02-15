class Solution {
public:
bool canPartition(int num,int target){
    if(target<0 or num<target) return false;
    if(num==target) return true;
    return canPartition(num/10,target-num%10) or canPartition(num/100,target-num%100) or canPartition(num/1000,target-num%1000);
}
    int punishmentNumber(int n) {
        int res=0;
        for(int cur=1;cur<=n;cur++){
            int sq=cur*cur;
            if(canPartition(sq,cur)) res+=sq;
        }
        return res;
    }
};