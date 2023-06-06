class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int minVal=arr[0];
        for(int i=1;i<arr.size();i++)
            minVal=min(minVal,arr[i]);
        int maxVal=arr[0];
        for(int i=1;i<arr.size();i++)
            maxVal=max(maxVal,arr[i]);
        int n=arr.size();
        if((maxVal-minVal)%(n-1)!=0) return false;
        int diff=(maxVal-minVal)/(n-1);
        int i=0;
        while(i<n)
        {
            if(arr[i]==minVal+i*diff) i+=1;
            else if((arr[i]-minVal)%diff!=0) return false;
            else
            {
                int j=(arr[i]-minVal)/diff;
                if(arr[i]==arr[j]) return false;
                swap(arr[i],arr[j]);
            }
        }
        return true;
    }
};