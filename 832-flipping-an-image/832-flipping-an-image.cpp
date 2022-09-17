class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int m=image.size();
        int n=image[0].size();
        int p1,p2;
        for(int i=0;i<m;i++)
        {
            p1=0;
            p2=n-1;
            while(p1<=p2)
            {
                int temp=!image[i][p1];
                image[i][p1]=!image[i][p2];
                image[i][p2]=temp;
                p1++;
                p2--;
            }
        }
        return image;
    }
};