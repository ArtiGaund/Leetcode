/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &Arr) {
        int length=Arr.length();
        // find the index of the peak element
        int low=1,high=length-2;
        while(low!=high)
        {
            int index=(low+high)>>1;
            int cur=Arr.get(index);
            int next=Arr.get(index+1);
            if(cur<next)
            {
                if(cur==target) return index;
                if(next==target) return index+1;
                low=index+1;
            }
            else high=index;
        }
        int peakIndex=low;
        // find in the strictly increasing part
        low=0;
        high=peakIndex;
        while(low<=high)
        {
            int index=(low+high)>>1;
            int cur=Arr.get(index);
            if(cur==target) return index;
            else if(cur<target) low=index+1;
            else high=index-1;
        }
        //find in the strictly decreasing part
        low=peakIndex+1;
        high=length-1;
        while(low<=high)
        {
            int index=(low+high)>>1;
            int cur=Arr.get(index);
            if(cur==target) return index;
            else if(cur>target) low=index+1;
            else high=index-1;
        }
        // not present
        return -1;
    }
};