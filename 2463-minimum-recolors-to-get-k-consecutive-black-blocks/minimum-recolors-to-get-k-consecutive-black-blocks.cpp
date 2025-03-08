class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int left=0,noWhites=0,noRecolors=INT_MAX;
        for(int right=0;right<blocks.size();right++){
            if(blocks[right]=='W') noWhites++;
            if(right-left+1==k){
                noRecolors=min(noWhites,noRecolors);
                if(blocks[left]=='W') noWhites--;
                left++;
            }
        }
        return noRecolors;
    }
};