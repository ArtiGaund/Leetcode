class Solution {
public:
    static int findWeight(int num)
    {
        int w=0;
        while(num>0){
            w++;
            num&=(num-1);
        }
        return w;
    }
    static bool compare(int a,int b){
        if(findWeight(a)==findWeight(b)) return a<b;
        return findWeight(a)<findWeight(b);
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),compare);
        return arr;
    }
};