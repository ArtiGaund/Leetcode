class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        return quick(points,k);
    }
    vector<vector<int>> quick(vector<vector<int>> &p,int k)
    {
        int left=0,right=p.size()-1;
        int pivot=p.size();
        while(pivot!=k)
        {
            pivot=partition(p,left,right);
            if(pivot<k) left=pivot;
            else right=pivot-1;
        }
        return vector<vector<int>>(p.begin(),p.begin()+k);
    }
    int partition(vector<vector<int>> &p,int left,int right)
    {
        vector<int> &pivot=choosePivot(p,left,right);
        int pivotDis=squaredDis(pivot);
        while(left<right)
        {
            if(squaredDis(p[left])>=pivotDis)
            {
                swap(p[left],p[right]);
                right--;
            }
            else left++;
        }
        if(squaredDis(p[left])<pivotDis) left++;
        return left;
    }
    vector<int> &choosePivot(vector<vector<int>> &p,int left,int right)
    {
        return p[left+(right-left)/2];
    }
    int squaredDis(vector<int> &p)
    {
        return p[0]*p[0]+p[1]*p[1];
    }
};