class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int i=0,j=0; //cur index for nums1 and nums2
        int count;
        double m1=-1,m2=-1;
        for(count=0;count<=(m+n)/2;count++)
        {
            m2=m1;
            if(i!=n and j!=m)
                m1=(nums1[i]>nums2[j]?nums2[j++]:nums1[i++]);
            else if(i<n) m1=nums1[i++];
            else m1=nums2[j++];
        }
        if((m+n)%2) return m1;
        else return (m1+m2)/2;
        
    }
};