class Solution {
public:
    int maximumSwap(int num) {
        string numStr=to_string(num);
        int n=numStr.size();
        int maxDigitIndex=-1,swapIndex1=-1,swapIndex2=-1;
        for(int i=n-1;i>=0;i--){
            if(maxDigitIndex==-1 or numStr[i]>numStr[maxDigitIndex])
                maxDigitIndex=i;
            else if(numStr[i]<numStr[maxDigitIndex]){
                swapIndex1=i;
                swapIndex2=maxDigitIndex;
            }
        }
        if(swapIndex1!=-1 and swapIndex2!=-1) swap(numStr[swapIndex1],numStr[swapIndex2]);
        return stoi(numStr);
    }
};