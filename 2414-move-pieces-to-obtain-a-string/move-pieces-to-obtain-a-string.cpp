class Solution {
public:
    bool canChange(string start, string target) {
        int startLen=start.size();
        int startIndex=0,targetIndex=0;
        while(startIndex<startLen or targetIndex<startLen){
            while(startIndex<startLen and start[startIndex]=='_'){
                startIndex++;
            }
            while(targetIndex<startLen and target[targetIndex]=='_'){
                targetIndex++;
            }
            if(startIndex==startLen or targetIndex==startLen){
                return (startIndex==startLen and targetIndex==startLen);
            }
            if(start[startIndex] != target[targetIndex] or (start[startIndex]=='L' and startIndex<targetIndex) or (start[startIndex]=='R' and startIndex>targetIndex)) return false;
            startIndex++;
            targetIndex++;
        }
        return true;
    }
};